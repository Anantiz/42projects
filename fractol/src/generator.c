/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:52:48 by aurban            #+#    #+#             */
/*   Updated: 2023/11/14 12:24:09 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	generate_fractal(int (*f)(t_i*, t_i*), int width, int height, int res)
{
	return ;
}

int	mandlebrot_set(t_i *z, t_i *c)
{
	z->i = pow(z->i, 2) + c->i;
	z->r = pow(z->r, 2) + c->r;
	return (0);
}

int	julia_set(t_i *z, t_i *c)
{
	return (0);
}