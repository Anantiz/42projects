/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:42:18 by aurban            #+#    #+#             */
/*   Updated: 2023/11/03 20:13:19 by aurban           ###   ########.fr       */
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

char	*get_next_line(int fd);
ssize_t	refill_buff(int fd, char *buff);
char	*resize_line(char *s1, size_t added_size);
char	*get_buff(int fd, char **buffers_list);

#endif
