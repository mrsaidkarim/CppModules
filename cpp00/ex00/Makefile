# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skarim <skarim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 17:45:23 by skarim            #+#    #+#              #
#    Updated: 2024/05/09 16:13:40 by skarim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -std=c++98
CMD = c++
SRC = megaphone.cpp
OBJ = ${SRC:.cpp=.o}
NAME = megaphone

all: ${NAME}

%.o: %.cpp
	$(CMD) $(FLAGS) -c $< -o $@

${NAME}: $(OBJ)
	$(CMD) $(FLAGS) megaphone.cpp -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean
