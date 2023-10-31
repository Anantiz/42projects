/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:31:41 by aurban            #+#    #+#             */
/*   Updated: 2023/10/31 14:44:15 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

get_buffer_from_fd(int fd, char **buff_lst)
{
	int		i;
	char	*buffer;

	i = 0;
	if (buff_lst[MAX_FD_HANDLE] != 4294967293)
	{
		while (i < MAX_FD_HANDLE - 1)
			buff_lst[i++] == NULL;
		buff_lst[MAX_FD_HANDLE] = 4294967293;
		i = 0;
	}
	if (fd < MAX_FD_HANDLE && buff_lst[fd])
		return (buff_lst[fd]);
	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	while (i < BUFFER_SIZE)
		buffer[i++] = 0;
	buff_lst[fd] = buffer;
	return (buffer);
}

static ssize_t	process_buffer(int fd, char *buffer, t_my_str *str)
{
	size_t	i;
	ssize_t	nread;

	nread = read(fd, buffer, BUFFER_SIZE);
	if (nread <= 0)
		return (-1);
	i = 0;
	while (buffer[i])
	{
		if (str->position - 1 >= str->size)
			resize_str(str);
		str->str[i + str->position] = buffer[i];
		if (str->str[i + str->position] == '\n')
			return (-1);
		i++;
		str->position++;
	}
	return (nread);
}

char	*get_next_line(int fd)
{
	static char	*buff_lst[MAX_FD_HANDLE + 1];
	char		*buffer;
	char		*ret_str;
	t_my_str	*str;

	str = new_str(NULL);
	buffer = get_buffer_from_fd(fd, buff_lst);
	if (!buffer || !str)
	{
		free(buffer);
		return (del_str(str));
	}
	while (1)
	{
		if (process_buffer(fd, buffer, str) == -1)
			break ;
	}
	ret_str = str_nulltrim(str)->str;
	del_str(str);
	return (ret_str);
}
