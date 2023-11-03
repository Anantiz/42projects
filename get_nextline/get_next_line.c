/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:42:06 by aurban            #+#    #+#             */
/*   Updated: 2023/11/03 21:14:46 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define RESIZE_CHUNK 256

static void	move_index_to_front(char *buffer, size_t index)
{
	size_t	j;

	j = 0;
	while (index < BUFFER_SIZE && buffer[index])
		buffer[j++] = buffer[index++];
	buffer[j] = '\0';
}

int	read_buffer_copy_loop(char *buff, char *line, size_t *i, size_t *l_offst)
{
	char	*old_line;

	if ((*i + *l_offst) % RESIZE_CHUNK == 0)
	{
		old_line = line;
		line = resize_line(line, RESIZE_CHUNK);
		free(old_line);
		if (line == NULL)
		{
			buff[0] = '\0';
			return (-1);
		}
	}
	while (*i < BUFFER_SIZE && buff[*i] != '\0' && buff[*i] != '\n')
	{
		line[*i + *l_offst] = buff[*i];
		(*i)++;
	}
	if ((buff[*i] == '\0' || buff[*i] == '\n'))
	{
		line[*i + *l_offst] = buff[*i];
		move_index_to_front(buff, *i + 1);
		return (420);
	}
	return (0);
}

static char	*read_buffer(int fd, char *buff, char *line)
{
	size_t	i;
	size_t	l_offst;
	int		status;

	l_offst = 0;
	while (1)
	{
		i = 0;
		if (!buff[i])
		{
			if (refill_buff(fd, buff) < 0)
			{
				free (line);
				line = NULL;
				break ;
			}
		}
		status = read_buffer_copy_loop(buff, line, &i, &l_offst);
		if (status == -1)
			return (NULL);
		else if (status == 420)
			return (line);
		l_offst += i;
	}
	return (line);
}

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
