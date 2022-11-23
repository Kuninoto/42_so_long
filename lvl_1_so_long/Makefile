# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 23:48:22 by nnuno-ca          #+#    #+#              #
#    Updated: 2022/11/20 23:11:05 by nnuno-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L ./mlx -lmlx -Ilmlx -lXext -lX11
RM = rm -rf
NAME = so_long

# cc cflags main.c libft.a mlxflags -o NAME

SRCS = main.c
OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) --no-print-directory -C ./libft
	@$(MAKE) --no-print-directory -C ./mlx
	echo "\033[36mMaking so_long..."
#	$(CC) $(OBJS) $()

#%.o: %c
#	$(CC) $(CFLAGS) -c $*.c

bonus: all

clean:
	$(RM) $(OBJS)
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
re: fclean all