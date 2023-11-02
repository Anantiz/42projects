/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:40:18 by aurban            #+#    #+#             */
/*   Updated: 2023/11/02 11:45:16 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
Allocate new memory space for a larger string.
Copies the current string into the new space and padd
	the remaining space with zeros
return (str);
*/
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
		return (str);
	i = 0;
	if (str->str != NULL)
	{
		while (str->str[i])
		{
			new_str[i] = str->str[i];
			i++;
		}
		free(str->str);
	}
	while (i < str->size)
		new_str[i++] = 0;
	str->str = new_str;
	return (str);
}

/*
Realocate a new str->str without null padding
*/
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
		new_str = NULL;
		if (!new_str)
			return (str);
		i = 0;
		while (str->str[i++])
			new_str[i - 1] = str->str[i - 1];
		new_str[i - 1] = '\0';
		str->size = i - 1;
		free(str->str);
		str->str = new_str;
	}
	return (str);
}

/*
To upgrade once I can Use Libft
Size includes the NULL charachter
*/
t_my_str	*create_new_str(size_t size)
{
	t_my_str	*new_struct;
	size_t		i;

	new_struct = malloc(sizeof(t_my_str));
	if (!new_struct)
		return (NULL);
	new_struct->size = size;
	new_struct->pos = 0;
	if (size)
	{
		new_struct->str = malloc((size) * sizeof(char));
		if (!new_struct->str)
		{
			free(new_struct);
			return (NULL);
		}
		i = 0;
		while (i < size)
			new_struct->str[i++] = '\0';
	}		
	else
		new_struct->str = NULL;
	return (new_struct);
}

void	*del_str(t_my_str *str)
{
	if (str)
		free(str->str);
	free(str);
	return (NULL);
}

char	*free_str(t_my_str *str)
{
	char	*temp;

	temp = NULL;
	if (str && str->str)
		temp = str->str;
	if (str)
		free(str);
	return (temp);
}
