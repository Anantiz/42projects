/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:58:09 by aurban            #+#    #+#             */
/*   Updated: 2023/11/02 19:27:56 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main()
{
	int	fd1, fd2;
	char *line;
	fd1 = open("file1", O_RDONLY);
	fd2 = 0;
	
	//fd2 = open("file2", O_RDONLY);

	for (int i = 1; i < 7 ; i++)
	{
		line = get_next_line(fd1);
		if (line)
		{
			printf("%s", line);
			free(line);
		}
		if (fd2)
		{
			line = get_next_line(fd2);
			if (line)
			{
				printf("%s", line);
				free(line);
			}
		}
	}
	close (fd1);
	if (fd2)
		close (fd2);
	return (0);
}