CMD = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Harl.cpp main.cpp
HDR = Harl.hpp
OBJ = ${SRC:.cpp=.o}
NAME = harl

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