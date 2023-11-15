/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_formulas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:15:57 by aurban            #+#    #+#             */
/*   Updated: 2023/11/15 17:54:08 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define MAX_ITER 24
#define MAX_CONVERGE ULONG_MAX

#define GREEN	0x00FF1CFF
#define CYAN	0x001C00FF
#define BLUE	0x0000CCFF
#define PURPLE	0x30046EFF
#define BLACK	0x000000FF
#define PINK	0xFFC0CBFF

static unsigned int get_color(unsigned int n)
{
	n = MAX_ITER - n;
	ft_printf("N = %u\t",n);
	if (n == 0)
		return (BLACK);
	else if (n < 5)
		return (PURPLE);
	else if (n < 10)
		return (BLUE);
	else if (n < 15)
		return (GREEN);
	else if (n < 24)
		return (CYAN);
	else
		return (PINK);
}

unsigned int	mandlebrot_set(t_i *c)
{
	unsigned int	n;
	t_i				z;

	z.r = c->r;
	z.i = c->i;
	n = MAX_ITER;
	while (n > 1)
	{
		z.r = (z.r * z.i) - (z.i * z.r) + c->r;
		z.i = (z.r * z.i) + (z.i * z.r) + c->i;
		n--;
		if ((z.r * z.r + z.i * z.i) > MAX_CONVERGE)
			break ;
		if (z.r == c->r && z.i == c->i)
			return (0);
	}
	return (get_color(n));
}

unsigned int	julia_set(t_i *c)
{
	unsigned int	n;
	t_i				z;

	z.r = c->r;
	z.i = c->i;
	n = MAX_ITER;
	while (n > 1)
	{
		z.r = (z.r * z.i) - (z.i * z.r) + c->r;
		z.i = (z.r * z.i) + (z.i * z.r) + c->i;
		n--;
		if ((z.r * z.r + z.i * z.i) > MAX_CONVERGE)
			break ;
		if (z.r == c->r && z.i == c->i)
			return (0);
	}
	return (get_color(n));
}