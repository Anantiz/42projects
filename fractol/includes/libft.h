/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:44:18 by aurban            #+#    #+#             */
/*   Updated: 2023/11/12 16:13:56 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

/* MEMORY */

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

/* STRING -----------------------------------------------*/
/* UTILS */
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlen(const char *s);

/* CHECK */
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/* CONVERSIONS */
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_uitohex(unsigned int n);
char	*ft_uitohex_up(unsigned int n);
char	*ft_ltohex(long n);
char	*ft_ltohex_up(long n);
char	*ft_ultohex(unsigned long n);
char	*ft_ultohex_up(unsigned long n);


/* MEMORY */
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(const char *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));


/* FILES ------------------------------------------------*/
void	ft_putchar_fd(char s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* LINKED LIST */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *node);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));


/* PRINTF -----------------------------------------------*/

# define SBUFSIZ 8192

typedef struct s_buffer_data
{
	int	offset;
	int	written;
}t_bd;

int		ft_printf(const char *s, ...);
void	ft_flush(int fd, char *buffer, t_bd *bd);

int		ft_arg_to_buffer(char *buffer, t_bd *bd, va_list *args, char c);
void	ft_send_char(char *buffer, t_bd *bd, char c);
void	ft_send_str(char *buffer, t_bd *bd, const char *str);
void	ft_send_ptr(char *buffer, t_bd *bd, void *ptr);
void	ft_send_decimal(char *buffer, t_bd *bd, int n);
void	ft_send_uint(char *buffer, t_bd *bd, unsigned int n);

#endif