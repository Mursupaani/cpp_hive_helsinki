# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/19 16:31:55 by anpollan          #+#    #+#              #
#    Updated: 2026/01/19 16:50:12 by anpollan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= megaphone
CPP_FILES	= megaphone.cpp
SRC_DIR		= ./src/
SRCS		= $(addprefix $(SRC_DIR), $(CPP_FILES))
OBJ_DIR		= ./obj/
OBJS		= $(addprefix $(OBJ_DIR), $(CPP_FILES:%.cpp=%.o))
CPP_FLAGS	= -Wall -Wextra -Werror -std=c++20

all: $(NAME)

$(NAME): $(OBJS)
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
