/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:42:18 by aurban            #+#    #+#             */
/*   Updated: 2023/11/06 12:26:12 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# if (BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647 )
#  define BUFFER_SIZE 4096
# endif

# define MAX_FD_HANDLE 1024

char	*get_next_line(int fd);

char	*get_buff(int fd, char **buffers_list);
ssize_t	refill_buff(int fd, char *buff);
char	*resize_line(char *s1, size_t added_size);
char	*str_nulltrim(char *str);

#endif
