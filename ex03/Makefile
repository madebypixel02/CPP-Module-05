# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperez-b <aperez-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 14:11:00 by aperez-b          #+#    #+#              #
#    Updated: 2022/09/30 10:58:29 by aperez-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp	\
	  RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

NAME = bureaucrat

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
