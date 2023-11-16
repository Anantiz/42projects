/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:59:52 by aurban            #+#    #+#             */
/*   Updated: 2023/11/16 14:47:32 by aurban           ###   ########.fr       */
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
	t_i				c;
	char			set;
	mlx_t			*mlx;
	mlx_image_t		*img;
}t_param;

int	generate_fractal(t_param *p);

unsigned int	julia_set(t_i *c);
unsigned int	mandlebrot_set(t_i *c);

int	args_help();
int	error_invalid_set(char *set);
int	error_invalid_constant(char **argv, int argc, int error);

#endif