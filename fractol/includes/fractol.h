/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:59:52 by aurban            #+#    #+#             */
/*   Updated: 2023/11/13 17:19:50 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"

void	generate_fractal(void (*f)(void), int width, int height, int resolution);

void	julia_set(t_idouble z);
void	mandlebrot_set(t_idouble z);

typedef struct s_idouble
{
	double	i;
	double	r;
}t_idouble;


#endif