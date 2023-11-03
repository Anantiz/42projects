/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:20:20 by aurban            #+#    #+#             */
/*   Updated: 2023/11/03 12:34:12 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_my_str	*get_buff(int fd, t_my_str **buff_lst)
{
	t_my_str	*new_str;

	if (fd >= MAX_FD_HANDLE)
		return (NULL);
	if (buff_lst[fd])
		return (buff_lst[fd]);
	new_str = create_new_str(BUFFER_SIZE);
	if (!new_str || !new_str->str)
		return (del_str(new_str));
	buff_lst[fd] = new_str;
	return (new_str);
}

static ssize_t	read_file(int fd, t_my_str *r_buff)
{	
	ssize_t	nread;

	nread = 0;
	if (r_buff->pos == 0 || r_buff->pos == r_buff-> size)
	{
		r_buff->pos = 0;
		nread = read(fd, r_buff->str, r_buff->size);
		if (nread >= 0)
			r_buff->size = (size_t) nread;
	}
	return (nread);
}

static int	fill_out_str(int fd, t_my_str *r_buff, t_my_str *out)
{
	ssize_t	nread;

	nread = 1;
	while (nread > 0)
	{
		if (r_buff->pos == 0 || r_buff->pos == r_buff->size)
		{
			nread = read_file(fd, r_buff);
			if (nread < 0)
				return (-2);
		}
		while (r_buff->pos < r_buff->size - 1)
		{
			if (r_buff->str[r_buff->pos] == '\0')
				return (2);
			if (out->pos >= out->size)
				if (resize_str(out) == -1)
					return (-1);
			out->str[out->pos++] = r_buff->str[r_buff->pos++];
			if (out->str[out->pos - 1] == '\n')
				return (1);
		}
	}
	return (nread);
}

char	*get_next_line(int fd)
{
	static t_my_str		*buff_lst[MAX_FD_HANDLE];
	t_my_str			*read_buff;
	t_my_str			*out_str;
	int					code;

	read_buff = get_buff(fd, buff_lst);
	if (!read_buff)
		return (NULL);
	out_str = create_new_str(0);
	if (!out_str)
		return (NULL);
	code = fill_out_str(fd, read_buff, out_str);
	if (code == 2)
	{
		del_str(read_buff);
		buff_lst[fd] = NULL;
	}
	else if (code == -1 || code == -2)
		return (del_str(out_str));
	else if (code == 69)
		return (free_str(out_str));
	return (free_str(str_nulltrim(out_str)));
}
