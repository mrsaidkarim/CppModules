CMD = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = RPN.cpp main.cpp
HDR = RPN.hpp
OBJ = ${SRC:.cpp=.o}
NAME = RPN

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