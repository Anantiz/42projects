#include "libftprintf/ft_printf.h"
#include <stdio.h>

char *foo()
{
	return (malloc(0));
}

int	main(void)
{
	int og_result = printf("%s\nsomething", foo());
	printf("\n_\n");
	int result = ft_printf("%s\nsomething", foo());
	printf("\n");
	printf("----------\n");
	printf("OG Return: %d\n",og_result);
	printf("Return:    %d\n",result);
	
	return (0);
}
