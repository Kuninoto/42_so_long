# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 19:35:50 by nnuno-ca          #+#    #+#              #
#    Updated: 2023/02/09 00:42:31 by nnuno-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I../includes
RM = rm -rf
NAME = libft.a

LIB_SRCS = ft_isalpha.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c\
		   ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c\
	  	   ft_memcmp.c ft_strnstr.c ft_atoi.c ft_atol.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		   ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putnbr_fd.c\
		   ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		   ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\
		   get_next_line.c is_onstr.c\
		   ft_printf.c prt_str.c prt_ptr.c prt_int.c prt_unsigned.c prt_hexa.c\
		   join_free.c join_freev2.c free_matrix.c streq.c ft_strcpy.c\
		   only_spaces.c is_all_digits.c join_free_both.c trim_free.c\
		   
LIB_OBJS =  $(LIB_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIB_OBJS)
	ar rc $(NAME) $(LIB_OBJS)
clean:
	$(RM) $(LIB_OBJS) 
fclean: clean
	$(RM) $(NAME)
re: fclean all

.SILENT: