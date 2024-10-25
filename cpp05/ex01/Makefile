CMD = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Form.cpp Bureaucrat.cpp main.cpp
HDR = Form.hpp Bureaucrat.hpp
OBJ = ${SRC:.cpp=.o}
NAME = bureaucrat

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