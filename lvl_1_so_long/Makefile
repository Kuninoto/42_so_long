# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 23:48:22 by nnuno-ca          #+#    #+#              #
#    Updated: 2022/11/25 22:17:04 by nnuno-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L ./mlx -lmlx -Ilmlx -lXext -lX11
LIBFT = ./libft/libft.a
RM = rm -rf
NAME = so_long

SRCS = srcs/handle_error.c\
	   srcs/map/get_map.c srcs/map/map_check.c srcs/map/path_check.c\
	   srcs/tilemap.c\
	   srcs/mlx_hooks.c\
	   srcs/initializers.c\
	   main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	echo "\033[36mMaking libft...\033[0m"
	$(MAKE) --no-print-directory -C ./libft
	echo "\033[36mDone\033[0m"
	echo "\033[36mMaking mlx...\033[0m"
	$(MAKE) --no-print-directory -C ./mlx
	echo "\033[36mDone\033[0m"
	echo "\033[36mMaking so_long...\033[0m"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	echo "\033[36mDone!\033[0m"

bonus: all

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)
	echo "\033[36mDone!\033[0m"
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
re: fclean all

.SILENT: