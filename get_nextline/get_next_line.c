/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:42:06 by aurban            #+#    #+#             */
/*   Updated: 2023/11/03 13:25:26 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define RESIZE_CHUNK 64

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

static char	*put_buffer_in_line(char *buff, char *line)
{
	size_t	i;
	size_t	l_offst;

	i = 0;
	l_offst = 0;
	while (buff[i])
	{
		line[i] = buff[i];
		if (buff[i] == '\n' || buff[i] == '\0') // New line found, just return it, and clean buffer
		{
			move_buffer_to_front();
			break ;
		}
		if (i + l_offst == RESIZE_CHUNK)
		{
			line = resize_line(line, i + l_offst + RESIZE_CHUNK);
			l_offst = i;
		}
	}
	return (line);
}

static char	*read_buffer(int fd, char *buff, char *line)	
{
	ssize_t	nread;

	if (*buff == 0)
		nread = read(fd, buff, BUFFER_SIZE);
	if (*buff != 0 && nread >= 0)
	{
		line = put_buffer_in_line(buff, line);
		return (line);
	}
	else
		return (clean_everything(buff, line));
}

char	*get_next_line(int fd)
{
	static char	*buffers_list[MAX_FD_HANDLE];
	char		*line;
	char		*buff;

	buff = get_buff(fd, buffers_list);
	if (!buff)
		return (NULL);
	line = resize_line(NULL, RESIZE_CHUNK);
	if (!line)
	{
		free(buff);
		return (NULL);
	}
	line = read_buffer(fd, buff, line); // Will only ever return Either a valid full line or NULL
	if (line == NULL)
		free(buffers_list[fd]);
	return (line);
}
