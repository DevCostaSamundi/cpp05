NAME = aforms
CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

FILES = main.cpp \
	Bureaucrat.cpp \
	AForm.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp \
	Intern.cpp

HEADERS = Bureaucrat.hpp \
	  AForm.hpp \
	  ShrubberyCreationForm.hpp \
	  RobotomyRequestForm.hpp \
	  PresidentialPardonForm.hpp \
	  Intern.hpp

OBJS = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
