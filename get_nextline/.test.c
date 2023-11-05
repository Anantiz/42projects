/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:58:09 by aurban            #+#    #+#             */
/*   Updated: 2023/11/05 13:10:29 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main()
{
	int	fd1, fd2;
	char *line;
	fd1 = open(".file1.txt", O_RDONLY);
	fd2 = 0;
	
	// fd2 = open(".ftest.txt", O_RDONLY);

	// printf("FD1=%d\tFD2=%d\n\n",fd1, fd2);

	for (int i = 1; i < 9; i++)
	{
		// fflush(stdout);
		line = get_next_line(fd1);
		// fflush(stdout);
		printf("FD_1_LINE %d:%s/\n", i,line);
		// fflush(stdout);
		free(line);
		if (fd2)
		{
			// fflush(stdout);
			line = get_next_line(fd2);
			// fflush(stdout);
			printf("FD_2_LINE %d:%s/\n",i, line);
			// fflush(stdout);
			free(line);
		}
	}
	close (fd1);
	if (fd2)
		close (fd2);
	return (0);
}
