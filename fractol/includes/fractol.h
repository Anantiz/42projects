/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:59:52 by aurban            #+#    #+#             */
/*   Updated: 2023/11/15 16:09:50 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft.h"
# include "../MLX42/include/MLX42/MLX42_Int.h"

typedef struct s_idouble
{
	double	i;
	double	r;
}t_i;

typedef struct s_param
{
	unsigned int	w;
	unsigned int	h;
	float			res;
	unsigned int	(*f)(t_i *);
	mlx_t			*mlx;
	mlx_image_t		*img;
}t_param;

int	generate_fractal(t_param *p);

unsigned int	julia_set(t_i *c);
unsigned int	mandlebrot_set(t_i *c);

#endif