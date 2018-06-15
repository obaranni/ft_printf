# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obaranni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 11:12:50 by obaranni          #+#    #+#              #
#    Updated: 2018/05/31 16:19:16 by obaranni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = ./src/

OBJ_DIR = ./obj/

HEADER_DIR = ./headers/

LIB_DIR = ./libft/

LIBFT = $(LIB_DIR)libft.a

SRC = $(shell ls src)

OBJ = $(SRC:.c=.o)

SRC_LIB = $(shell ls libft)

OBJ_LIB = $(SRC_LIB:.c=.o)

SRC_FILES = $(addprefix $(SRC_DIR),$(SRC))

OBJ_FILES = $(addprefix $(OBJ_DIR),$(OBJ))

OBJ_LIB_FILES = $(addprefix $(LIB_DIR),$(OBJ_LIB))

COMPALING_FLAGS = -I$(HEADER_DIR) -I$(LIB_DIR) -Wall -Wextra -Werror

LINKING_FLAGS = -lft -L$(LIB_DIR)

CC = gcc

all:$(OBJ_FILES) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	$(CC) $(COMPILING_FLAGS) -o $@ -c $<

$(NAME): $(LIBFT) $(OBJ_DIR)
	 ar rc $(NAME) $(OBJ_FILES) $(OBJ_LIB_FILES)


$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(LIBFT):
	make -C $(LIB_DIR)

clean:
	rm -rf $(OBJ_FILES)
	make clean -C $(LIB_DIR)

fclean: clean
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all
