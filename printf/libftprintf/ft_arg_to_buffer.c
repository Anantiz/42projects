/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_to_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:06:49 by aurban            #+#    #+#             */
/*   Updated: 2023/10/29 06:40:50 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_send_char(char *buffer, t_bd *bd, char c)
{
	if (bd->offset == SBUFSIZ)
		ft_flush(1, buffer, bd);
	if (c == '\n')
	{
		buffer[bd->offset++] = c;
		ft_flush(1, buffer, bd);
	}
	else
		buffer[bd->offset++] = c;
}

void	ft_send_str(char *buffer, t_bd *bd, char *str)
{
	if (!str)
		return (ft_send_ptr(buffer, bd, str));
	while (*str)
	{
		if (bd->offset == SBUFSIZ)
			ft_flush(1, buffer, bd);
		if (*str == '\n')
		{
			buffer[bd->offset++] = *(str++);
			ft_flush(1, buffer, bd);
		}
		else
			buffer[bd->offset++] = *(str++);
	}
}

void	ft_send_ptr(char *buffer, t_bd *bd, void *ptr)
{
	char	*str;

	ft_send_char(buffer, bd, '0');
	ft_send_char(buffer, bd, 'x');
	if (ptr == NULL)
	{
		ft_send_char(buffer, bd, '0');
		return ;
	}
	str = ft_ultohex((unsigned long) ptr);
	ft_send_str(buffer, bd, str);
	free(str);
}

void	ft_send_decimal(char *buffer, t_bd *bd, int n)
{
	char	*n_str;

	n_str = ft_itoa(n);
	ft_send_str(buffer, bd, n_str);
	free(n_str);
}

void	ft_send_uint(char *buffer, t_bd *bd, unsigned int n)
{
	char	*n_str;

	n_str = ft_uitoa(n);
	ft_send_str(buffer, bd, n_str);
	free(n_str);
}
