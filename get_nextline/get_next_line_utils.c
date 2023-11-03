/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:13:20 by aurban            #+#    #+#             */
/*   Updated: 2023/11/03 20:29:27 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*resize_line(char *s1, size_t added_size)
{
	char	*joined;
	size_t	i;
	size_t	j;
	size_t	joined_size;

	joined_size = 0;
	if (s1)
		while (s1[joined_size])
			joined_size++;
	joined_size += added_size;
	joined = malloc((joined_size + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[j])
			joined[i++] = s1[j++];
	}
	while (i <= joined_size)
		joined[i++] = '\0';
	return (joined);
}

ssize_t	refill_buff(int fd, char *buff)
{
	ssize_t	nread;

	nread = read(fd, buff, BUFFER_SIZE);
	if (nread >= 0)
		buff[nread] = '\0';
	else
		buff[0] = '\0';
	return (nread);
}

char	*get_buff(int fd, char **buffers_list)
{
	size_t	i;

	if (fd > MAX_FD_HANDLE || fd < 0)
		return (NULL);
	if (buffers_list[fd])
		return (buffers_list[fd]);
	buffers_list[fd] = malloc(BUFFER_SIZE + 1);
	if (!buffers_list[fd])
		return (NULL);
	i = 0;
	while (i < BUFFER_SIZE)
		buffers_list[fd][i++] = '\0';
	return (buffers_list[fd]);
}
