/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultohex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:20:17 by aurban            #+#    #+#             */
/*   Updated: 2023/10/28 18:35:27 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	to_base(int c)
{
	if (c < 10)
		return ((char)(c + '0'));
	else
		return ((char)(c + 'a' - 10));
}

static void	fill_buffer(unsigned long n, char *buffer)
{
	if (n > 15)
		fill_buffer(n / 16, buffer - 1);
	*buffer = to_base(n % 16);
}

char	*ft_ultohex(unsigned long n)
{
	unsigned long	ncpy;
	char			*buffer;
	int				digits;

	ncpy = n;
	digits = 0;
	if (n == 0)
		digits++;
	while (ncpy)
	{
		digits++;
		ncpy /= 16;
	}
	buffer = malloc(sizeof(char) * (digits + 1));
	if (!buffer)
		return (NULL);
	fill_buffer(n, buffer + digits - 1);
	buffer[digits] = '\0';
	return (buffer);
}

static void	fill_buffer_up(unsigned long n, char *buffer)
{
	int	c;

	if (n > 15)
		fill_buffer_up(n / 16, buffer - 1);
	c = to_base(n % 16);
	if (c > '9')
		c -= 32;
	*buffer = c;
}

char	*ft_ultohex_up(unsigned long n)
{
	unsigned long	ncpy;
	char			*buffer;
	int				digits;

	ncpy = n;
	digits = 0;
	if (n == 0)
		digits++;
	while (ncpy)
	{
		digits++;
		ncpy /= 16;
	}
	buffer = malloc(sizeof(char) * (digits + 1));
	if (!buffer)
		return (NULL);
	fill_buffer_up(n, buffer + digits - 1);
	buffer[digits] = '\0';
	return (buffer);
}
