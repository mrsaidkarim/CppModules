
FLAGS = -Wall -Werror -Wextra -std=c++98
CMD = c++
SRC = Account.cpp tests.cpp
OBJ = ${SRC:.cpp=.o}
NAME = Account
HEADERS = Account.hpp

%.o: %.cpp $(HEADERS)
	$(CMD) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CMD) $(OBJ) -o $@

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean
