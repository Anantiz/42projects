/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:52:52 by aurban            #+#    #+#             */
/*   Updated: 2023/11/17 16:59:51 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	map_pixel_to_point(t_i *pixel_coordinates, t_param *p)
{
	long double	r;
	long double	i;

	r = pixel_coordinates->r * p->zoom * p->screen_resolution;
	i = pixel_coordinates->i * p->zoom * p->screen_resolution;
	pixel_coordinates->r = r;
	pixel_coordinates->i = i;
	//printf("ZOMM=%LF, RESO=%LF\t",p->zoom, p->screen_resolution);
	//printf("px r=%LF i%Lf\n", r, i);
}

int	ft_init_image(t_param *p)
{
	t_i				pixel_coordinates;
	unsigned int	pixel_x;
	unsigned int	pixel_y;
	
	//y 1:-1	x 1:-2
	/*
	0:0 will be middle of the image 2/3 right
	*/
	p->img_origin.r = p->w - (p->w / 3);
	p->img_origin.i = p->h / 2;
	printf("W=%u H=%u\n",p->w, p->h);
	printf("origin R=%LF\torigin I=%LF\n",p->img_origin.r, p->img_origin.i);
	/*
	1_pixel = 4 * uint_8
	pixels  = w * h * 1_pixel
	*/

	pixel_y = 0;
	while (pixel_y < p->h)
	{
		pixel_x = 0;
		while (pixel_x < p->w)
		{
			pixel_coordinates.r = pixel_x - p->img_origin.r;
			pixel_coordinates.i = pixel_y - p->img_origin.i;
			printf("GRAPH  x=%.2LF px=%u  y=%.2LF py=%u\t\t",pixel_coordinates.r, pixel_x, pixel_coordinates.i, pixel_y);
			map_pixel_to_point(&pixel_coordinates, p);
			mlx_put_pixel(p->img, pixel_x, pixel_y, mandlebrot_set(&pixel_coordinates));
			pixel_x++;
			fflush(stdout);
		}
		pixel_y++;
	}
	return (0);
}