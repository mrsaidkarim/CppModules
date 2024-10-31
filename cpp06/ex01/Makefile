CMD = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Serializer.cpp main.cpp
HDR = Serializer.hpp Data.hpp
OBJ = ${SRC:.cpp=.o}
NAME = serializer

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