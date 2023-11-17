/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:57:51 by aurban            #+#    #+#             */
/*   Updated: 2023/11/17 12:12:45 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int	init_param(char **argv, int argc, t_param *p)

static void	init_set(char *str, t_param *p)
{
	int	error;

	if (*str == 'M' || *str == 'm') //MANDLEBROT
		p->set = 'M';
	else if (*str == 'J' || *str == 'j') // JULIA
	{
		p->set = 'J';
		error = ft_atoz(&p->c , str);
		if (error)
		{
			p->set =  0;
			error_invalid_constant(error);
		}
	}
	else
	{
		p->set = 0;
		error_invalid_set(*str);
	}
}

int	main(int argc, char **argv)
{
	t_param	param;
	int		error;

	if (argc == 1)
		return (args_help());
	init_param(argv, argc, &param);
	if (param.set == 0)
		return (error_invalid_set(*argv[1]));
	param.zoom = 1.0;
	error = generate_fractal(&param);
	if (error)
		ft_printf("ERROR, could not open window error:%d\n", error);
	//free_params(&param);
	return (0);
}