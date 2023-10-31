/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:26:57 by aurban            #+#    #+#             */
/*   Updated: 2023/10/31 14:29:06 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int fd = open("testfile", O_RDONLY);
	
	int i = 0;
	while (i < 5)
	{
		line = get_next_line(fd);
		printf("%s", line);
		i++;
	}
	close(fd);
	return (0);
}