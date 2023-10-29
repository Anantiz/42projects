/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_to_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:06:49 by aurban            #+#    #+#             */
/*   Updated: 2023/10/29 06:01:02 by aurban           ###   ########.fr       */
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
	int	ncp;

	ncp = ft_strappendmax(buffer, str, (size_t) bd->offset, SBUFSIZ);
	bd->offset += ncp;
	if (ncp < (int) ft_strlen(str))
	{
		ft_flush(1, buffer, bd);
		ft_send_str(buffer, bd, str + ncp);
	}
}

void	ft_send_ptr(char *buffer, t_bd *bd, void *ptr)
{
	char	*str;
	int		ncp;

	ft_send_char(buffer, bd, '0');
	ft_send_char(buffer, bd, 'x');
	if (ptr == NULL)
	{
		ft_send_char(buffer, bd, '0');
		return ;
	}
	str = ft_ultohex((unsigned long) ptr);
	ncp = ft_strappendmax(buffer, str, (size_t) bd->offset, SBUFSIZ);
	bd->offset += ncp;
	if (ncp < (int) ft_strlen(str))
	{
		ft_flush(1, buffer, bd);
		ft_strappendmax(buffer, str + ncp, (size_t) bd->offset, SBUFSIZ);
	}
	free(str);
}

void	ft_send_decimal(char *buffer, t_bd *bd, int n)
{
	char	*n_str;
	int		ncp;

	n_str = ft_itoa(n);
	ncp = ft_strappendmax(buffer, n_str, (size_t) bd->offset, SBUFSIZ);
	bd->offset += ncp;
	if (ncp < (int) ft_strlen(n_str))
	{
		ft_flush(1, buffer, bd);
		ft_strappendmax(buffer, n_str + ncp, (size_t) bd->offset, SBUFSIZ);
	}
	free(n_str);
}

void	ft_send_uint(char *buffer, t_bd *bd, unsigned int n)
{
	char	*n_str;
	int		ncp;

	n_str = ft_uitoa(n);
	ncp = ft_strappendmax(buffer, n_str, (size_t) bd->offset, SBUFSIZ);
	bd->offset += ncp;
	if (ncp < (int) ft_strlen(n_str))
	{
		ft_flush(1, buffer, bd);
		ft_strappendmax(buffer, n_str + ncp, (size_t) bd->offset, SBUFSIZ);
	}
	free(n_str);
}
