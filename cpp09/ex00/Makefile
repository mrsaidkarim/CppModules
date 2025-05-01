CMD = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = BitcoinExchange.cpp main.cpp
HDR = BitcoinExchange.hpp
OBJ = ${SRC:.cpp=.o}
NAME = btc

all: $(NAME)

%.o: %.cpp $(HDR)
	$(CMD) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CMD) $(OBJ) -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean