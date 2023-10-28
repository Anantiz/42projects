/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:33:40 by aurban            #+#    #+#             */
/*   Updated: 2023/10/28 16:37:12 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/ft_printf.h"
#include <stdio.h>

int	main(void)
{

	int result = printf(NULL);
	printf("Result: %d",result);
	return (0);
}
