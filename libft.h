/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:14:47 by llemmel           #+#    #+#             */
/*   Updated: 2025/06/30 13:57:30 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include "gnl/get_next_line_bonus.h"
# include "ft_printf/ft_printf.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_vector
{
	void	*data;
	size_t	len;
	size_t	max_size;
	size_t	data_size;
}	t_vector;

/* CHAR_FUNCTION */
extern int		ft_isalnum(int c);
extern int		ft_isalpha(int c);
extern int		ft_isdigit(int c);
int				ft_iswhite_space(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

/* MEM_FUNCTION */
extern void		ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void	*s, int c, size_t n);

/* STR_FUNCTION */
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);

/* CONVERTER_FUNCTION */
int				ft_atoi_safe(const char *nptr);
int				ft_atoi(const char *nptr);
char			*ft_itoa(int n);

/* WRITE_FUNCTION */
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);

/* LINKED_LIST_FUNCTION */
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* VECTOR_FUNCTION */
t_vector		*ft_vector_new(size_t size, size_t data_size);
void			ft_vector_reserve(t_vector *vector, size_t new_size);
void			ft_vector_free(t_vector *vector);
void			ft_vector_add(t_vector *vector, void *data);
void			ft_vector_rm(t_vector *vector, size_t index);
void			ft_vector_insert(t_vector *vector, void *data, size_t index);

#endif