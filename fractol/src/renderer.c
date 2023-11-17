/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:52:52 by aurban            #+#    #+#             */
/*   Updated: 2023/11/17 11:58:00 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define PIXEL_SIZE (4 * sizeof(unit_8))
#define PIXEL (w,x, y) ((w * y + x) * PIXEL_SIZE)

static void	map_pixel_to_point(t_i *pixel_coordinates, t_param *p)
{
	long double	r;
	long double	i;

	r = pixel_coordinates->r * p->zoom * p->screen_resolution;
	i = pixel_coordinates->i * p->zoom * p->screen_resolution;
	pixel_coordinates->r = r;
	pixel_coordinates->i = i;	
}

int	ft_init_image(t_param *p)
{
	t_i				pixel_coordinates;
	unsigned int	pixel_x;
	unsigned int	pixel_y;
	uint8_t			pixel;
	
	//y 1:-1	x 1:-2
	/*
	0:0 will be middle of the image 2/3 right
	*/
	p->img_origin.r = p->w - (p->w / 3);
	p->img_origin.i = p->h / 2;

	/*
	1_pixel = 4 * uint_8
	pixels  = w * h * 1_pixel
	*/

	while (pixel_y < p->h)
	{
		while (pixel_x < p->w)
		{
			pixel_coordinates.r = pixel_x - p->img_origin.r;
			pixel_coordinates.i = pixel_y - p->img_origin.i;
			map_pixel_to_point(&pixel_coordinates, p);
			pixel = &p->img->pixels[PIXEL_POS(p->w, pixel_x, pixel_y)];
			mlx_draw_pixel(pixel, mandlebrot(&pixel_coordinates));
			pixel_x++;
		}
		pixel_y++;
	}
	return (0);
}