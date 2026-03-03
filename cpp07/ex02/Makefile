NAME		= array

INCL_DIR	= ./incl/
HPP_FILES	= Array.hpp
INCLS		= $(addprefix $(INCL_DIR), $(HPP_FILES))

SRC_DIR		= ./src/
CPP_FILES	= main.cpp
SRCS		= $(addprefix $(SRC_DIR), $(CPP_FILES))

OBJ_DIR		= ./obj/
OBJ_FILES	= $(CPP_FILES:%.cpp=%.o)
OBJS		= $(addprefix $(OBJ_DIR), $(OBJ_FILES))
DEP			= $(OBJS:%.o=%.d)

# CPP_FLAGS	= -Wall -Wextra -Werror -std=c++20 -I$(INCL_DIR)
CPP_FLAGS	= -I$(INCL_DIR)
DEP_FLAGS	= -MMD -MP

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CPP_FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	c++ $(CPP_FLAGS) $(DEP_FLAGS) -c $< -o $@

-include $(DEP)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) compile_commands.json

re: fclean all

.PHONY: clean fclean re
