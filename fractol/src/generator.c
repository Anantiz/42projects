/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:52:48 by aurban            #+#    #+#             */
/*   Updated: 2023/11/15 16:32:10 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_draw_pixel(t_param *p, unsigned int i, unsigned int j\
	, unsigned int color)
{
	uint8_t			*pixel;
	
	pixel = (&p->img->pixels) + ((p->w * j) + i * sizeof(unsigned int));
	*(pixel++) = (uint8_t)(color >> 24);
	*(pixel++) = (uint8_t)(color >> 16);
	*(pixel++) = (uint8_t)(color >> 8);
	*(pixel++) = (uint8_t)(color & 0xFF);
}

static void	init_img(t_param *p)
{
	unsigned int	i;
	unsigned int	j;
	t_i				c;

	j = 0;
	c.i = 0;
	while (j < p->h)
	{
		i = 0;
		c.r = 0;
		while (i < p->w)
		{
			my_draw_pixel(p, i, j, f(&c));
			c.r += 1 * p->res;
			i++;
		}
		c.i += 1 * p->res;
		j++;
	}
}

int	generate_fractal(t_param *p)
{
	p->mlx = mlx_init(p->w, p->h, "Fract'ol", true);
	if (!p->mlx)
		return (-1);
	p->img = mlx_new_image(p->mlx, p->w, p->h);
	if (!p->img)
		return (-2);
	if (mlx_image_to_window(p->mlx, p->img, 0, 0) < 0)
		return (-3);
	memset(p->img->pixels, 255, p->img->width * p->img->height * sizeof(int32_t));
	init_img(p);
	mlx_loop(p->mlx);
	return (0);
}