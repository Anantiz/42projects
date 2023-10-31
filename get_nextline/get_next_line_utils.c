/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:40:18 by aurban            #+#    #+#             */
/*   Updated: 2023/10/31 11:22:20 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_my_str	*resize_str(t_my_str *str)
{
	char	*new_str;
	size_t	i;

	if (str->str == NULL)
		str->size = 16;
	else
		str->size += str->size / 2;
	new_str = malloc((str->size + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	if (str->str)
	{
		while (str->str[i++])
			new_str[i - 1] = str->str[i - 1];
		free(str->str);
	}
	while (i < str->size)
		new_str[i++] = 0;
	return (new_str);
}

t_my_str	*str_nulltrim(t_my_str *str)
{
	size_t	i;
	char	*new_str;

	if (!str || !str->str)
		return (str);
	i = 0;
	while (str->str[i])
		i++;
	if (i < str->size)
	{
		new_str = malloc(sizeof(char) * (i + 1));
		if (!new_str)
			return (str);
		i = 0;
		while (str->str[i++])
			new_str[i - 1] = str->str[i - 1];
		new_str[i] = '\0';
		str->size = i;
		free(str->str);
		str->str = new_str;
	}
	return (str);
}

/*
To upgrade once I can Use Libft
*/
t_my_str	*new_str(const char *s)
{
	t_my_str	*new_str;
	char		*str_in;
	
	new_str = malloc(sizeof(t_my_str));
	if (!new_str)
		return (NULL);
	if (s)
		new_str->size = 1;
	else 
		new_str->size = 0;
	str_in = malloc(sizeof(char) * (new_str->size + 1));
	if (!str_in)
	{
		free(new_str);
		return (NULL);
	}
	str_in[new_str->size] = '\0';
	new_str->str = str_in;
	return (new_str);
}
void	del_str(t_my_str *str)
{
	if (str)
		free(str->str);
	free(str);
}