/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:24:23 by aurban            #+#    #+#             */
/*   Updated: 2023/11/16 18:10:27 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	args_help()
{
	ft_printf("Parameters:\n\t"
	"\n\t(1 arg)  Fractal Set:  'M'= Mandlebrot 'J'= Julia"
	"\n\t(2 args) (1)Set (2)set-Constant=xxixx Note:Only for supported sets"
	"\n\t(3 args) (1)Set (2)Width (3)Height    Note: Window size constrained"
	" between 128px and 3840x2160"
	"\n\t(4 args) (1)Set (2)Width (3)Height  (4)set-Constant\n");
	return (0);
}

int	error_invalid_set(char set)
{
	ft_printf("Invalid set argument, no valid set for '%c' or lacks"
	" arguments\n", set);
	return (0);
}

int	error_invalid_constant(int error)
{
	if (error == -1)
	{
		ft_printf("Invalid Argument count or wrong position for constant\n");
		args_help();
	}
	else
	{
		ft_printf("Could not convert argument into valid Complex Number\n"
		"argument must be as follow |real_part'i'complex_part| so 45i85"
		" == Real:45 Complex:85")	;
	}
	return (0);
}