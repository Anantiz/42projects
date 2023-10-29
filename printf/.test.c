

#include "libftprintf/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int og_result = printf(" NULL %s NULL ", NULL);
	printf("\n");
	int result = ft_printf(" NULL %s NULL ", NULL);
	printf("\n");
	printf("----------\n");
	printf("Return:    %d\n",result);
	printf("OG Return: %d\n",og_result);
	
	return (0);
}

