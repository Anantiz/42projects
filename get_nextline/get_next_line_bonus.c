/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:20:20 by aurban            #+#    #+#             */
/*   Updated: 2023/11/02 11:48:11 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_my_str	*get_buff(int fd, t_my_str **buff_lst)
{
	t_my_str	*new_str;

	if (fd > MAX_FD_HANDLE)
		return (NULL);
	if (buff_lst[fd])
		return (buff_lst[fd]);
	new_str = create_new_str(BUFFER_SIZE);
	if (!new_str || !new_str->str)
		return (del_str(new_str));
	buff_lst[fd] = new_str;
	return (new_str);
}

static int	fill_out_str(t_my_str *r_buff, t_my_str *out)
{
	char	*check_mem;

	while (r_buff->pos < r_buff->size && r_buff->str[r_buff->pos])
	{
		if (out->pos == out->size)
		{
			check_mem = out->str;
			resize_str(out);
			if (out->str == NULL || check_mem == out->str)
				return (-1);
		}
		out->str[out->pos++] = r_buff->str[r_buff->pos++];
		if (out->str[out->pos - 1] == '\n')
			return (-1);
	}
	if (r_buff->pos < r_buff->size && r_buff->str[r_buff->pos] == '\0')
	{
		out->str[out->pos] = r_buff->str[r_buff->pos];
		return (-1);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_my_str		*buff_lst[MAX_FD_HANDLE];
	t_my_str			*read_buff;
	t_my_str			*out_str;
	ssize_t				nread;

	read_buff = get_buff(fd, buff_lst);
	if (!read_buff)
		return (NULL);
	out_str = create_new_str(0);
	if (!out_str)
		return (NULL);
	while (1)
	{
		if (read_buff->pos == 0 || read_buff->pos == read_buff-> size)
		{
			read_buff->pos = 0;
			nread = read(fd, read_buff->str, read_buff->size);
			if (nread <= 0)
				break ;
			read_buff->size = nread;
		}
		if (fill_out_str(read_buff, out_str) == -1)
			break ;
	}
	return (free_str(str_nulltrim(out_str)));
}
