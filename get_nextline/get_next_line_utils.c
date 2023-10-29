/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:40:18 by aurban            #+#    #+#             */
/*   Updated: 2023/10/29 16:45:43 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strndup(const char *s, size_t len)
{
	char	*duplicate_str;
	size_t	i;

	duplicate_str = malloc((len + 1) * sizeof(char));
	if (duplicate_str == NULL)
		return (NULL);
	while (*s && i < len )
	{
		duplicate_str[i] = s[i];
		i++;
	}
	duplicate_str[len] = '\0';
	return (duplicate_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{	
	char	*end_ptr;

	if (!s)
		return (ft_strndup(""), 0);
	end_ptr = (char *)s;
	while (*end_ptr)
		end_ptr++;
	if (end_ptr - start < s)
		return (ft_strndup("", 0));
	if (len > (size_t)(end_ptr - (s + start)))
		len = end_ptr - (s + start);
	return (ft_strndup(s + start, len));
}
