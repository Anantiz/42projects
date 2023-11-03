/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:13:20 by aurban            #+#    #+#             */
/*   Updated: 2023/11/03 13:17:16 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*resize_line(char *old_line, size_t new_size)
{
	char	*new_line;
	size_t	i;
	
	new_line = malloc(new_size + 1);
	if (!new_line)
	{
		free(old_line);
		return (NULL);
	}
	i = 0;
	if (old_line)
	{
		while (old_line[i])
		{
			new_line[i] = old_line[i];
			i++;
		}
	}
	while (i <= new_size)
		new_line[i++] = '\0';
	free(old_line);
	return (new_line);
}
