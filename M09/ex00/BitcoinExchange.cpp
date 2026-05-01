#include "BitcoinExchange.hpp"
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _db = other._db;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// ── helpers ──────────────────────────────────────────────────────────────────

// Validate "YYYY-MM-DD" and check calendar ranges
bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7) continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }

    int year  = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day   = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    // Months with 30 days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    // February
    bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (month == 2 && day > (leap ? 29 : 28))
        return false;

    return true;
}

// Parse value and validate range [0, 1000]
bool BitcoinExchange::isValidValue(const std::string &valueStr, double &out) const
{
    std::istringstream iss(valueStr);
    double val;
    if (!(iss >> val))
        return false;

    std::string leftover;
    if (iss >> leftover)
        return false;   // trailing garbage

    if (val < 0.0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (val > 1000.0)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    out = val;
    return true;
}

// Find closest date <= requested date using lower_bound
double BitcoinExchange::getRate(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it = _db.lower_bound(date);

    if (it == _db.end() || it->first != date)
    {
        // No exact match: step back to the nearest earlier date
        if (it == _db.begin())
            throw std::runtime_error("no data available for date: " + date);
        --it;
    }
    return it->second;
}

// ── public interface ──────────────────────────────────────────────────────────

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");

    std::string line;
    std::getline(file, line); // skip header "date,exchange_rate"

    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        std::size_t comma = line.find(',');
        if (comma == std::string::npos) continue;

        std::string date     = line.substr(0, comma);
        std::string rateStr  = line.substr(comma + 1);

        double rate = atof(rateStr.c_str());
        _db[date] = rate;
    }
}

void BitcoinExchange::processInput(const std::string &filename) const
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // skip header "date | value"

    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        // Expect format: "date | value"
        std::size_t pipe = line.find(" | ");
        if (pipe == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date     = line.substr(0, pipe);
        std::string valueStr = line.substr(pipe + 3);

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        double value = 0.0;
        if (!isValidValue(valueStr, value))
            continue;   // error message already printed

        try
        {
            double rate   = getRate(date);
            double result = value * rate;
            std::cout << date << " => " << value << " = " << result << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}