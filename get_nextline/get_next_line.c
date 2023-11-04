/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:42:06 by aurban            #+#    #+#             */
/*   Updated: 2023/11/04 12:32:59 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#if (BUFFER_SIZE > 256)
# define RESIZE_CHUNK 2048
#else 
# define RESIZE_CHUNK 256
#endif

static void	move_index_to_front(char *buffer, size_t index)
{
	size_t	j;

	j = 0;
	if (buffer[index++] != '\0')
		while (index < BUFFER_SIZE && buffer[index])
			buffer[j++] = buffer[index++];
	buffer[j] = '\0';
}

static int	summon_resize(int i, int l_offst, char **buff, char **line)
{
	if ((i + l_offst) % RESIZE_CHUNK == 0)
	{
		*line = resize_line(*line, RESIZE_CHUNK);
		if (*line == NULL)
		{
			(*buff)[0] = '\0';
			return (-1);
		}
	}
	return (0);
}

int	copy_buffer(char **buff, char **line, size_t *i, size_t *l_offst)
{
	if (summon_resize(*i, *l_offst, buff, line) == -1)
		return (-1);
	while (*i < BUFFER_SIZE && (*buff)[*i] != '\0' && (*buff)[*i] != '\n')
	{
		if (summon_resize(*i, *l_offst, buff, line) == -1)
			return (-1);
		(*line)[*i + *l_offst] = (*buff)[*i];
		(*i)++;
	}
	if (*i < BUFFER_SIZE && ((*buff)[*i] == '\n' || (*buff)[*i] == '\0' ))
	{
		(*line)[*i + *l_offst] = (*buff)[*i];
		move_index_to_front((*buff), *i);
		if (*i != 0 && (*buff)[*i] == '\0')
			return (0);
		else
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
	i = 0;
	while (1)
	{
		if (!buff[0] || (i == BUFFER_SIZE))
		{
			if (refill_buff(fd, buff) < 0)
			{
				free (line);
				return (NULL);
			}
		}
		i = 0;
		status = copy_buffer(&buff, &line, &i, &l_offst);
		if (status == -1)
			return (NULL);
		else if (status == 420)
			return (line);
		l_offst += i;
	}
}
#include <stdio.h>
char	*get_next_line(int fd)
{
	static char	*buffers_list[MAX_FD_HANDLE];
	char		*line;
	char		*buff;

	buff = get_buff(fd, buffers_list);
	if (!buff)
	{
		printf("INVALIDE BUFF: FD=%d\n", fd);
		fflush(stdout);
		return (NULL);
	}
	line = read_buffer(fd, buff, NULL);
	printf("str:%s/\n", line);
	printf("buf:%s/\n", buff);
	fflush(stdout);
	if (line == NULL || (buff && buff[0] == '\0'))
	{
		free(buffers_list[fd]);
		buffers_list[fd] = NULL;
	}
	if (line && line[0] == '\0')
	{
		free(line);
		line = NULL;
	}
	return (str_nulltrim(line));
}
