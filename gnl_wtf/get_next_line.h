/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:06:55 by aurban            #+#    #+#             */
/*   Updated: 2023/11/02 20:00:14 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# define MAX_FD_HANDLE 1024

typedef struct s_my_str
{
	char	*str;
	size_t	size;
	size_t	pos;
}t_my_str;

char		*get_next_line(int fd);

/*
Supper string class
*/

char		*free_str(t_my_str *str);
void		*del_str(t_my_str *str);
t_my_str	*create_new_str(size_t size);
int			resize_str(t_my_str *str);
t_my_str	*str_nulltrim(t_my_str *str);

#endif