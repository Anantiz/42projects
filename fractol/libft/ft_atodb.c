/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:25:28 by aurban            #+#    #+#             */
/*   Updated: 2023/11/16 18:14:54 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	get_decimal(char *str)
{
	double	result;
	int		i;

	result = 0.0;
	i = 10;
	while(ft_isdigit((int)(*str)))
	{
		result += (1 / i) * ((*str) - '0');
		i *= 10;
	}
	return (result);
}

double	ft_atodb(char *str)
{
	double		result;	
	long long	left;

	result = 0.0;
	left = ft_atoll(str);
	while(*str != '.' && *str != ',' && *str)
		str++;
	result += left;
	if (*str++)
		result += get_decimal(str);
	return (result);
}
