CMD = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Zombie.cpp randomChump.cpp newZombie.cpp main.cpp
HDR = Zombie.hpp
OBJ = ${SRC:.cpp=.o}
NAME = Zombie

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