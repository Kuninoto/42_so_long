/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 01:35:12 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/02/09 00:29:58 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *str);
void				*ft_memset(void *ptr, int x, size_t n);
void				ft_bzero(void *ptr, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, char *src, size_t size);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);

/* Converts a string to an integer */
int					ft_atoi(const char *str);

/* Converts a string to a ssize_t */
ssize_t				ft_atol(const char *str);

void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s1, char const *set);
char				*trim_free(char *s1, char const *set);

char				**ft_split(char const *s, char c);
char				**split_per_set(char const *s, const char *set);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Writes a character into fd
 * 
 * @param c  Character to write
 * @param fd File descriptor to write to  
 */
static inline void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

/**
 * @brief Writes str into fd
 * 
 * @param str String to write
 * @param fd File descriptor to write to
 */
static inline void	ft_putstr_fd(char *str, int fd)
{
	if (!str || fd < 0)
		return ;
	write(fd, str, ft_strlen(str));
}

/**
 * @brief Writes str, followed by a newline, into fd
 * 
 * @param str String to write
 * @param fd  File descriptor to write to
 */
static inline void	ft_putendl_fd(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	write(fd, "\n", 1);
}

void				ft_putnbr_fd(int n, int fd);

// LINKED LISTS ---------------------------------

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// Creates a new node
t_list				*ft_lstnew(void *content);
// Adds a new node at the front of the linked list
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);

/* Returns a pointer to the last node of the linked list */
t_list				*ft_lstlast(t_list *lst);

/* Adds a new node at the tail of the linked list */
void				ft_lstadd_back(t_list **head, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// GET_NEXT_LINE ---------------------------------
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif 

/**
 * @brief Returns a line, ending in newline (if any),
 * 		  read from a file descriptor
 * 
 * @param fd File descriptor to read from
 */
char				*get_next_line(int fd);
bool				is_onstr(const char *str, int ch);

// FT_PRINTF --------------------------------------

/* Prints formatted output to STDOUT */
int					ft_printf(const char *__format, ...);
int					prt_str(char const *str);
int					prt_ptr(void *ptr_addr);
int					prt_int(int n);
int					prt_unsigned(unsigned int nbr);
int					prt_hexa(unsigned int nbr, bool upper_case);

// UTILS -------------------------------------------

/* Returns s1+s2, creating a new string, and frees s1  */
char				*join_free(char *s1, char *s2);
/* Returns s1+s2, creating a new string, and frees s2 */
char				*join_freev2(char *s1, char *s2);
/* Returns s1+s2, creating a new string and frees both s1 and s2 */
char				*join_free_both(char *s1, char *s2);

/* Frees all elements in the matrix and its pointer */
void				free_matrix(char **matrix);

/* Checks if both strings passed as parameters are absolutely equal */
bool				streq(char *str1, char *str2);

/* Return a literal copy of to_copy (useful when 
you want to free to_copy for some reason) */
char				*ft_strcpy(char *to_copy);

static inline bool	is_spaces(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (true);
	return (false);
}

/**
 * @brief Checks if a string is only composed by whitespaces
 * 
 * @param str String to analyze
 */
bool				only_spaces(const char *str);

/* Returns true if str is only composed by digits */
bool				is_all_digits(char *str);

#endif
