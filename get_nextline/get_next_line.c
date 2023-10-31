/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:31:41 by aurban            #+#    #+#             */
/*   Updated: 2023/10/31 19:44:07 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "limits.h"

static t_my_str	*get_buffer_from_fd(int fd, t_my_str **buff_lst)
{
	int			i;
	t_my_str	*buffer;

	if (!buff_lst[MAX_FD_HANDLE])	
	{
		buff_lst = malloc(sizeof(t_my_str *) * MAX_FD_HANDLE + 1));
		if (!buff_lst)
			return (NULL);
	}
	if (fd < MAX_FD_HANDLE && buff_lst[fd])
	{
		return (buff_lst[fd]);
	}
	else	
	buffer = new_str(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	buff_lst[fd] = buffer;
	return (buffer);
}

static ssize_t	process_buffer(int fd, t_my_str *buffer, t_my_str *str)
{
	size_t	i;
	ssize_t	nread;

	nread = read(fd, buffer->str, BUFFER_SIZE);
	if (nread <= 0)
	{
		buffer->position = 0;
		return (-1);
	}
	i = 0;
	while (i + buffer->position < BUFFER_SIZE)
	{
		str->str[i + str->position] = buffer->str[i + buffer->position];
		if (buffer->str[i + buffer->position] == '\n')
		{
			str = str_nulltrim(str);
			buffer->position = i;
			return (-1);
		}
		i++;
	}
	str->position += i;
	buffer->position = 0;
	return (nread);
}

char	*get_next_line(int fd)
{
	static t_my_str	**buff_lst;
	t_my_str		*buffer;
	t_my_str		*str;
	char			*ret_str;

	str = resize_str(new_str(0));
	buffer = get_buffer_from_fd(fd, buff_lst);
	if (!buffer || !str)
	{
		free(buffer);
		return (del_str(str));
	}
	while (1)
		if (process_buffer(fd, buffer, str) == -1)
			break ;
	ret_str = str->str;
	free (str);
	return (ret_str);
}
