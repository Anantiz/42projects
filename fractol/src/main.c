/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:57:51 by aurban            #+#    #+#             */
/*   Updated: 2023/11/17 14:55:53 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_param	param;
	int		error;

	if (argc == 1)
		return (args_help());
	if (init_param(argv, argc, &param))
		return (0);
	error = generate_fractal(&param);
	if (error)
		ft_printf("ERROR, could not open window error:%d\n", error);
	//free_params(&param);
	return (0);
}