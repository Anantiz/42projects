/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_formulas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:15:57 by aurban            #+#    #+#             */
/*   Updated: 2023/11/17 17:03:22 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define MAX_ITER 64
#define MAX_CONVERGE 2

#define GREEN	0x00FF1CFF
#define CYAN	0x001C00FF
#define BLUE	0x0000CCFF
#define PURPLE	0x30046EFF
#define BLACK	0x000000FF
#define PINK	0xFFC0CBFF


/*
	Blue shift for faster infinity
	Red  shift for slower infinity
*/
static unsigned int get_color(unsigned int n)
{
	unsigned int	color;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	double			normalized_n;

	n = MAX_ITER - n;
	if (n == MAX_ITER)
	{
		ft_printf("n=%u\tcolor=%X\n",n, BLACK);
		return (BLACK);
	}
	normalized_n = n / MAX_ITER;
	red = (unsigned int)(normalized_n * 180);
	green = (unsigned int)(normalized_n * 67);
	blue = (unsigned int)(normalized_n * 200);
	color = (red << 24) + (green << 16) + (blue << 8) + 255;
	ft_printf("n=%u\tcolor=%u\n",n, color);
	return (color);
}

unsigned int	mandlebrot_set(t_i *c) // C is a constant based on pixel value, Z starts at 0
{
	int			n;
	long double	zr;
	t_i			z;

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