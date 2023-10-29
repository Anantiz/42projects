/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:15:02 by aurban            #+#    #+#             */
/*   Updated: 2023/10/29 05:52:39 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Flushes the buffer to the file descriptor and update t_buffer_data
*/
void	ft_flush(int fd, char *buffer, t_bd *bd)
{
	bd->written += bd->offset;
	write(fd, buffer, bd->offset);
	bd->offset = 0;
}

static void	init_bd(t_bd *bd)
{
	bd->offset = 0;
	bd->written = 0;
}

static int	read_format(const char *s, va_list *args)
{
	char	buffer[SBUFSIZ];
	t_bd	bd;

	init_bd(&bd);
	while (*s)
	{
		if (bd.offset == SBUFSIZ)
			ft_flush(1, buffer, &bd);
		if (*s == '\n')
		{
			buffer[bd.offset++] = *(s++);
			ft_flush(1, buffer, &bd);
		}
		else if (*s == '%')
		{
			if (ft_arg_to_buffer(buffer, &bd, args, *(++s)))
				return (-1);
			s++;
		}
		else
			buffer[bd.offset++] = *(s++);
	}
	ft_flush(1, buffer, &bd);
	return (bd.written);
}

static int	check_input(const char *s)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] != 'c' && s[i] != 's' && s[i] != 'p' && \
			s[i] != 'd' && s[i] != 'i' && s[i] != 'u' && \
			s[i] != 'x' && s[i] != 'X' && s[i] != '%')
				return (-2);
		}
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		check;

	check = 0;
	check = check_input(format);
	if (check)
		return (check);
	va_start(args, format);
	check = read_format(format, &args);
	va_end(args);
	return (check);
}
