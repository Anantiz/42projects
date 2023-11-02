/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:26:57 by aurban            #+#    #+#             */
/*   Updated: 2023/11/02 11:39:27 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int fd = open("testfile", O_RDONLY);
	
	int i = 1;
	while (i < 8)
	{
		line = get_next_line(fd);
		printf("/Line n %d :\n%s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}

