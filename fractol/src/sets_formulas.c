/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_formulas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:15:57 by aurban            #+#    #+#             */
/*   Updated: 2023/11/17 10:50:31 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define MAX_ITER 16
#define MAX_CONVERGE 2

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

unsigned int	mandlebrot_set(t_i *c) // C is a constant based on pixel value, Z starts at 0
{
	unsigned int	n;
	long double		zr;
	t_i				z;

	z.r = c->r;
	z.i = c->i;
	n = MAX_ITER;
	while (n > 0)
	{
		zr = z.r;
		z.r = (z.r * z.i) - (z.i * z.r) + c->r;
		z.i = (zr * z.i) + (z.i * zr) + c->i;
		n--;
		if ((z.r * z.r + z.i * z.i) > MAX_CONVERGE)
			break ;
	}
	return (get_color(n));
}

unsigned int	julia_set(t_i *z, t_i *c) // C is a constant given as input, Z starts with the pixel
{
	unsigned int	n;
	long double		zr;

	n = MAX_ITER;
	while (n > 0)
	{
		zr = z->r;
		z->r = (z->r * z->i) - (z->i * z->r) + c->r;
		z->i = (zr * z->i) + (z->i * zr) + c->i;
		n--;
		if ((z->r * z->r + z->i * z->i) > MAX_CONVERGE)
			break ;
	}
	return (get_color(n));
}