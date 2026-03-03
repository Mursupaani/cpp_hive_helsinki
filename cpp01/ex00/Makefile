NAME		= brainz

INCL_DIR	= ./incl/
HPP_FILES	= Zombie.hpp
INCLS		= $(addprefix $(INCL_DIR), $(HPP_FILES))

SRC_DIR		= ./src/
CPP_FILES	= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
SRCS		= $(addprefix $(SRC_DIR), $(CPP_FILES))

OBJ_DIR		= ./obj/
OBJ_FILES	= $(CPP_FILES:%.cpp=%.o)
OBJS		= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

CPP_FLAGS	= -Wall -Wextra -Werror -std=c++20 -I$(INCL_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(INCLS)
	c++ $(CPP_FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	mkdir -p $(OBJ_DIR)
	c++ $(CPP_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
