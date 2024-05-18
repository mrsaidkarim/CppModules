CMD = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = replace.cpp main.cpp
HDR = replace.hpp
OBJ = ${SRC:.cpp=.o}
NAME = sed

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