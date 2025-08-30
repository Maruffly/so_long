/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaruffy <jmaruffy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:40:16 by jmaruffy          #+#    #+#             */
/*   Updated: 2024/09/02 16:11:19 by jmaruffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>

// IS CHAR
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);

// STR
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(char *s1, char *s2, size_t length);
int		ft_atoi(char *str);
size_t	ft_strlcpy(char *dest, char *src, size_t len);
size_t	ft_strlen(char *c);
size_t	ft_strlcat(char *dest, char *src, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(char	*str, int c);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strmapi(char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_itoa(int n);
char	*ft_strdup(char *src);
char	**ft_split(char *s, char c);
void	free_substr(char **sub_str, int words);
int		count_words(char *s, char sep);
int		ft_printf(char *str, ...);
char	*get_next_line(int fd);

// MEMORY
int		ft_memcmp(void *s1, void *s2, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memmove(void *dest, void *src, size_t n);
void	*ft_memset(void *dest, int c, size_t n);
void	*ft_memcpy(void *dest, void *src, size_t n);
void	*ft_memchr(void *str, int c, size_t n);
void	*ft_calloc(size_t nb_element, size_t size_element);

// FD PRINT
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

// LIST
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_putchar(int c, int *count_char);
void	ft_putstr(char *s, int *count_char);
void	ft_putnbr(long int nb, int *count_char, int is_unsigned);
void	ft_puthexa(unsigned long long int n, int *count_char, char specifier);
void	ft_putptr(unsigned long int ptr, int *count);

#endif
