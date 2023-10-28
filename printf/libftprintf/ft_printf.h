/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:50:15 by aurban            #+#    #+#             */
/*   Updated: 2023/10/28 18:05:25 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

# define BUFSIZ 8192

typedef struct s_type_ct
{
	int		*types;
	size_t	count;
	size_t	size;
}t_type_ct;

int		ft_printf(const char *s, ...);
void	ft_flush(int fd, char *buffer, int *buffer_offset);

void	ft_send_str(char *buffer, int *offset, char *arg);

char	*ft_ultohex(unsigned long n);
char	*ft_ultohex_up(unsigned long n);

#endif