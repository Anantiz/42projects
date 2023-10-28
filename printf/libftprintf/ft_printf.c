/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:15:02 by aurban            #+#    #+#             */
/*   Updated: 2023/10/28 16:33:16 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_arg_to_buffer(char *buffer, int *offset, va_list *args, char c)
{
	char	*ch;
	void	*p;
	
	switch (c)
	{
		case ('c'):
			*ch = va_arg(*args, char);
			ft_send_char(buffer, offset, ch);
			break ;
		case ('s'):
			ch = va_arg(*args, char*);
			ft_send_str(buffer, offset, ch);
			break ;
		case ('p'):
			p = va_arg(*args, void*);
			ft_send_ptr(buffer, offset, p);
			break;
			
	}
}

void	ft_flush(int fd, char *buffer, int *buffer_offset)
{
	write(fd, buffer, *buffer_offset);
	*buffer_offset = 0;
}

int	ft_printf(const char *s, ...)
{
	//t_type_ct	*type_ct;
	va_list		args;
	char		buffer[BUFSIZ];

	if (!s)
		return (-1);
	va_start(args, s);
	
	va_end(args);
	return (0);
}

/*
static size_t	get_count(const char *s)
{
	size_t		count;

	count = 0;
	while (*s)
	{
		if (*s == '%')
			count++;
		s++;
	}
	return (count);
}

static int	*get_types(const char *s, size_t count)
{
	int		*types;
	size_t	j;

	types = malloc(count * sizeof(int));
	if (!types)
		return (NULL);
	j = 0;
	while (*s && j < count)
	{
		if (*s == '%' && *(s + 1))
		{
			if (*s == 'c' || *s == 's' || *s == 'p' || *s == 'd' || *s == 'i'\
			|| *s == 'u' || *s == 'x' || *s == 'X' || *s == '%')
				types[j++] = *(s + 1);
		}
		s++;
	}
	return (types);
}

static t_type_ct	*get_type_ct(const char *s)
{
	t_type_ct	*type_ct;

	type_ct = malloc(sizeof(t_type_ct));
	if (!type_ct)
		return (NULL);
	type_ct->count = get_count(s);
	type_ct->types = get_types(s, type_ct->count);
	if (!type_ct->types)
		return (NULL);
	return (type_ct);
}
*/