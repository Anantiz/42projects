#include "libftprintf/ft_printf.h"
#include <stdio.h>

char *foo()
{
	return (NULL);
}

int	main(void)
{
	printf("%s", NULL);
	ft_printf("%s", NULL);
	printf("\n");
	printf("----------\n");
	// printf("OG Return: %d\n",og_result);
	// printf("Return:    %d\n",result);
	
	return (0);
}
