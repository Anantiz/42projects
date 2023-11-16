/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:57:51 by aurban            #+#    #+#             */
/*   Updated: 2023/11/16 14:47:21 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 450
#define MAX_WIDTH 3840
#define MAX_HEIGHT 2160
#define MIN_SIZE 128


static void	init_size(char **argv, int argc, t_param *p)
{
	if (argc > 3)
	{
		p->w = ft_atoi(argv[2]);
		p->h = ft_atoi(argv[3]);
		if (p->w < MIN_SIZE || p->w > MAX_WIDTH)
		{
			ft_printf("Invalid Width, default value used instead\n");
			p->w = DEFAULT_WINDOW_WIDTH;
		}
		if (p->h < MIN_SIZE || p->h > MAX_HEIGHT)
		{
			ft_printf("Invalid Height, default value used instead\n");
			p->h = DEFAULT_WINDOW_HEIGHT;
		}
	}
	else
	{
		p->w = DEFAULT_WINDOW_WIDTH;
		p->h = DEFAULT_WINDOW_HEIGHT;
	}
}

static int	ft_atoz(t_i *z, char *str)
{
	
}

static void	int_res_set(char **argv, int argc, t_param *p)
{
	int	error;

	if (*argv[1] == 'M' || *argv[1] == 'm') //MANDLEBROT
		p->set = 'M';
	else if (*argv[1] == 'J' || *argv[1] == 'j') // JULIA
	{
		error = -1;
		p->set = 'J';
		if (argc == 5)
			error = ft_atoz(&p->c ,argv[4]);
		else if (argc == 3)
			error = ft_atoz(&p->c ,argv[2]);
		if (error)
			p->set = error_invalid_constant(argv, argc, error); // If Juilia set was given check if constant is present
	}
	else
		p->set = 0;
	}

int	main(int argc, char **argv)
{
	t_param	param;
	int		error;

	if (argc == 1)
		return (args_help());
	init_size(argv, argc, &param);
	int_res_set(argv, argc, &param);
	if (param.set == 0)
		return (error_invalid_set(*argv[1]));
	error = generate_fractal(&param);
	if (error)
		ft_printf("ERROR, could not open window error:%d\n", error);
	return (0);
}