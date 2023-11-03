/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:42:06 by aurban            #+#    #+#             */
/*   Updated: 2023/11/03 17:05:35 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define RESIZE_CHUNK 256

static void	move_index_to_front(char *buffer, size_t index)
{
	size_t	j;

	j = 0;
	while (buffer[index] && index < BUFFER_SIZE)
		buffer[j++] = buffer[index++];
	buffer[j] = '\0';
}

/*
Always has to retrun line or free line if it returns null
*/
static char	*read_buffer(int fd, char *buff, char *line)
{
	size_t	i;
	size_t	l_offst;

	l_offst = 0;
	while (1)
	{
		i = 0;
		if (refill_buff(fd, buff) < 0)
		{
			free (line);
			return (NULL);
		}
		while (i < BUFFER_SIZE)
		{
			if ((i + l_offst) % RESIZE_CHUNK == 0)
			{
				line = resize_line(line, RESIZE_CHUNK);
				if (!line)
					return (NULL);
			}
			line[i + l_offst] = buff[i];
			if (buff[i] == '\n' || buff[i] == '\0')
			{
				move_index_to_front(buff, i + 1);
				return (line);
			}
			i++;
		}
		l_offst += i;
	}
}

static char	*get_buff(int fd, char **buffers_list);

char	*get_next_line(int fd)
{
	static char	*buffers_list[MAX_FD_HANDLE];
	char		*line;
	char		*buff;

	buff = get_buff(fd, buffers_list);
	if (!buff)
		return (NULL);
	line = read_buffer(fd, buff, NULL);
	if (line == NULL || buff[0] == '\0')
	{
		free(buffers_list[fd]);
		buffers_list[fd] = NULL;
	}
	if (line && line[0] == '\0')
	{
		free(line);
		line = NULL;
	}
	return (line);
}

static char	*get_buff(int fd, char **buffers_list)
{
	if (fd > MAX_FD_HANDLE || fd < 0)
		return (NULL);
	if (buffers_list[fd])
		return (buffers_list[fd]);
	buffers_list[fd] = malloc(BUFFER_SIZE + 1);
	if (!buffers_list[fd])
		return (NULL);
	buffers_list[fd][0] = '\0';
	buffers_list[fd][BUFFER_SIZE] = '\0';
	return (buffers_list[fd]);
}
