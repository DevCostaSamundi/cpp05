# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csamundi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 09:58:36 by csamundi          #+#    #+#              #
#    Updated: 2026/02/11 09:58:37 by csamundi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat
CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

FILES = Bureaucrat.cpp Form.cpp main.cpp
HEADERS = Bureaucrat.hpp Form.hpp
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
