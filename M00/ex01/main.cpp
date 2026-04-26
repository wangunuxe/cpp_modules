/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:44:51 by jili              #+#    #+#             */
/*   Updated: 2026/01/15 15:44:54 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
//THe main is only responsible for reading commands and delegating work to the PhoneBook object.
//The PhoneBook object lives only inside main
int	main()
{
	std :: string	command;
	Phonebook pb;

	while (true)
	{
		std::cout << "Please enter ADD, SEARCH or EXIT: ";
		if (!std::getline(std::cin, command))
			break;//Ctrl + D

		if (command == "ADD")
			pb.addContact();
		else if (command == "SEARCH")
			pb.searchContact();
		else if (command == "EXIT")
			break;
	}
	return 0;
}
