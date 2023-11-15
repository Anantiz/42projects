/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_formulas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:15:57 by aurban            #+#    #+#             */
/*   Updated: 2023/11/15 16:22:40 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define MAX_ITER 32
#define MAX_CONVERGE ULONG_MAX

#define GREEN	0x00FF1C
#define CYAN	0x001C00
#define BLUE	0x0000CC
#define PURPLE	0x30046E
#define BLACK	0x000000

static unsigned int get_color(unsigned int n)
{
	if (n == 0)
		return (BLACK);
	else if (n < 5)
		return (GREEN);
	else if (n < 10)
		return (CYAN);
	else if (n < 15)
		return (BLUE);
	else if (n < 20)
		return (PURPLE);
	else
		return (BLACK);
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