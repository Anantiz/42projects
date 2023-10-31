/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:31:41 by aurban            #+#    #+#             */
/*   Updated: 2023/10/31 11:24:55 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static szie_t	process_buffer(size_t nread, char *buffer, t_my_str *str)
{
	size_t	i;

	if(nread <= 0)
		return (-1);
	i = 0;
	while (buffer[i])
	
	
}

char	*get_next_line(int fd)
{
	static char	*buff_lst[MAX_FD_HANDLE];
	char		*buffer;
	char		*ret_str;
	t_my_str	*str;
	ssize_t		nread;

	str = new_str(NULL);
	buffer = malloc(BUFFER_SIZE);
	if (!buffer || !str)
	{
		free (buffer);
		del_str(str);
		return (NULL);
	}
	while (1)
	{
		nread = read(fd, buffer, BUFFER_SIZE);

		if (process_buffer(nread, buffer, &str) == -1)
			break ;
	}
	str = str_nulltrim(str);
	ret_str = str->str;
	del_str(str);
	return (ret_str)
}
