#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>

#define buffer_size 8

int main(void)
{
	char	buffer[buffer_size];
	int 	fd;
	ssize_t nread;
	int i;
	
	fd = open("file1.txt", O_RDONLY);
	printf("FD=%d.\n",fd);


	int j = 0;
	while (j <= 2)
	{
		nread = read(fd, buffer, buffer_size);
		printf("nread=%zi\n",nread);
		i = 0;
		while (i < buffer_size)
		{
			if (buffer[i])
				printf("%c",buffer[i]);
			else
				printf("X");
			i++;
		}
		printf("\n");
		j++;
	}
}