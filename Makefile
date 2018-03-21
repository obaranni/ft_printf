# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obaranni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/27 16:59:45 by obaranni          #+#    #+#              #
#    Updated: 2018/03/02 13:28:48 by obaranni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRC_DIR = ./src/

OBJ_DIR = ./obj/

INC_DIR = ./headers/

LIB_DIR = ./libft/

#ERR_FLAGS = -Wall -Wextra -Werror

LIBFT = $(LIB_DIR)libft.a

SRC = $(shell ls src)

OBJ = $(SRC:.c=.o)

SRC_FILES =	$(addprefix $(SRC_DIR),$(SRC))

OBJ_FILES =	$(addprefix $(OBJ_DIR),$(OBJ))

COMPALING_FLAGS = $(ERR_FLAGS) -I $(INC_DIR) -I $(LIB_DIR)

LINKING_FLAGS = -Wno-format-invalid-specifier -Wno-format -Wno-macro-redefined -Wno-implicitly-unsigned-literal -lft -L $(LIB_DIR)

CC = gcc

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(LINKING_FLAGS) $(OBJ_FILES) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(COMPALING_FLAGS) -o $@ -c $<

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
