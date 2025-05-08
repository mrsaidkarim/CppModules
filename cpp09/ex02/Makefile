CMD = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = PmergeMe.cpp PmergeMe.cpp
HDR = PmergeMe.hpp
OBJ = ${SRC:.cpp=.o}
NAME = PmergeMe

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