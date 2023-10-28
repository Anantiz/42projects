/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:15:02 by aurban            #+#    #+#             */
/*   Updated: 2023/10/28 11:57:48 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


/*
BAD METHOD TO COUNT TO CHANGE
*/
static size_t	get_count(const char *s)
{
	size_t		count;
	
	count = 0;
	while(*s)
	{
		if (*s == '%')
			count++;
		s++;
	}
	return (count);
}

t_ts	*get_types(const char *s, size_t count)
{
	t_ts	*types;
	size_t	i;
	size_t	j;

	types = malloc(count * sizeof(t_ts));
	if (!types)
		return (NULL);
	i = 0;
	j = 0; 
	while (s[i] && count > 0)
	{

		i++;
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

int	ft_printf(const char *s, ...)
{
	t_type_ct	*type_ct;
	va_list		args;
	size_t		var;
	
	if (!s)
		return (-1);
	type_ct = get_type_ct(s);
	if (!type_ct)
		return (-1);
	va_start(args, type_ct->count);
	var = 0;
	while(var < type_ct->count)
	{
		var++;
	}
	va_end(args);
	return (0);
}