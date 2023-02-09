# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 23:48:22 by nnuno-ca          #+#    #+#              #
#    Updated: 2023/02/08 23:43:21 by nnuno-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L ./mlx -lmlx -Ilmlx -lXext -lX11
INCLUDE = -I./includes
LIBFT = ./libft/libft.a
VPATH = srcs srcs/map srcs/utils
RM = rm -rf
NAME = so_long

UTILS = destroy panic
MAP = check_path get_map map_check render_map
GENERAL = init_mlx player hook_n_run

SRCS = $(addsuffix .c, $(UTILS))\
	   $(addsuffix .c, $(MAP))\
	   $(addsuffix .c, $(GENERAL))\
	   main.c

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR)  $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./mlx
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

bonus: all

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	
re: fclean all

run: all clean

.SILENT: