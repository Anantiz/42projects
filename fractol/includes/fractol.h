/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:59:52 by aurban            #+#    #+#             */
/*   Updated: 2023/11/14 12:30:49 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft.h"

typedef struct s_idouble
{
	double	i;
	double	r;
}t_i;

void	generate_fractal(int (*f)(t_i*, t_i*), int width, int height, int res);

int	julia_set(t_i *z, t_i *c);
int	mandlebrot_set(t_i *z, t_i *c);



#endif