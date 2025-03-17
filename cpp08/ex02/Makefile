CMD = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
HDR = MutantStack.hpp
OBJ = ${SRC:.cpp=.o}
NAME = a.out

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