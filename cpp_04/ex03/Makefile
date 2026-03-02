NAME		= materia

INCL_DIR	= ./incl/
HPP_FILES	= AMateria.hpp Ice.hpp Cure.hpp ICharacter.hpp Character.hpp MateriaSource.hpp
INCLS		= $(addprefix $(INCL_DIR), $(HPP_FILES))

SRC_DIR		= ./src/
CPP_FILES	= main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp
SRCS		= $(addprefix $(SRC_DIR), $(CPP_FILES))

OBJ_DIR		= ./obj/
OBJ_FILES	= $(CPP_FILES:%.cpp=%.o)
OBJS		= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

CPP_FLAGS	= -Wall -Wextra -Werror -std=c++20 -I$(INCL_DIR) -g

all: $(NAME)

$(NAME): $(OBJS) $(INCLS)
	c++ $(CPP_FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	c++ $(CPP_FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) compile_commands.json

re: fclean all

.PHONY: clean fclean re
