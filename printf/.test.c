

#include "libftprintf/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	unsigned int	something;
	int				smth;
	int				smth2;

	something = 646565;
	smth = 458;
	smth2 = -458;

	// int result=ft_printf("Hey!\tft_printf Here!\nDecimal:\t%d\nChar:\t\t%c\nUdecimal:\t%u\nptr:\t\t%p \nhex:\t\t%x\t%X\n"\
	// , 5, 'w', something, &something, smth, smth2);

	int result = ft_printf("%p", NULL);

	printf("\n");

	int og_result = printf("%p", NULL);
	printf("\n");

	// int og_result=printf("Hey!\tog_printf Here!\nDecimal:\t%d\nChar:\t\t%c\nUdecimal:\t%u\nptr:\t\t%p \nhex:\t\t%x\t%X\n"\
	// , 5, 'w', something, &something, smth, smth2);
	
	printf("----------\nReturn: %d\n",result);
	printf("OG Return: %d\n",og_result);
	
	return (0);
}

