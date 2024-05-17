CMD = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp
HDR = Weapon.hpp HumanA.hpp HumanB.hpp
OBJ = ${SRC:.cpp=.o}
NAME = violence

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