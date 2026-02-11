NAME = Bureaucrat
CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

FILES = Bureaucrat.cpp main.cpp
HEADERS = Bureaucrat.hpp
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