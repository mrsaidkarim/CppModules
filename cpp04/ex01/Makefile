CMD = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Animal.cpp Dog.cpp Cat.cpp Brain.cpp WrongAnimal.cpp WrongCat.cpp main.cpp
HDR = Animal.hpp Cat.hpp Dog.hpp Brain.hpp WrongAnimal.hpp WrongCat.hpp
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