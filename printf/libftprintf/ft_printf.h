/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:50:15 by aurban            #+#    #+#             */
/*   Updated: 2023/10/29 17:47:00 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

/*8192 4096 2048 1024*/

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

char	*ft_uitohex(unsigned int n);
char	*ft_uitohex_up(unsigned int n);
char	*ft_ltohex(long n);
char	*ft_ltohex_up(long n);
char	*ft_ultohex(unsigned long n);
char	*ft_ultohex_up(unsigned long n);

#endif