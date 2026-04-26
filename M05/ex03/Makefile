NAME = ex03
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I includes/

SRCS    = srcs/main.cpp \
          srcs/Bureaucrat.cpp \
          srcs/AForm.cpp \
          srcs/ShrubberyCreationForm.cpp \
          srcs/RobotomyRequestForm.cpp \
          srcs/PresidentialPardonForm.cpp \
		  srcs/Intern.cpp
		
#OBJS = $(SRCS: .cpp = .o)
OBJS = $(patsubst srcs/%.cpp, objs/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

objs/%.o : srcs/%.cpp
	mkdir -p objs/
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
	rm -rf objs/

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re