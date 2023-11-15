/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:57:51 by aurban            #+#    #+#             */
/*   Updated: 2023/11/15 16:15:30 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 450
#define DEFAULT_RESOLUTION 1
#define MAX_WIDTH 3840
#define MAX_HEIGHT 2160
#define MIN_SIZE 128

static int	args_help()
{
	ft_printf("Parameters:\n\t"
	"(0 arg)(default) set=M  Width=800  Height=450  Resolution=0.75"
	"\n\t(1 arg) Fractal Set:  'M'= Mandlebrot 'J'= Julia"
	"\n\t(2 arg) (1)Width (2)Height  Note: values are constrained"
	" between 128px and 3840x2160"
	"\n\t(3+ arg) (1)Set (2)Width (3)Height (4)(optional)Resolution a.k.a"
	"precision, must be between 0.2 and 1.5\n");
	return (0);
}

static void	init_size(char **argv, int argc, t_param *p)
{
	if (argc >= 3)
	{
		p->w = ft_atoi(argv[2]);
		p->h = ft_atoi(argv[3]);
		if (p->w < MIN_SIZE || p->w > MAX_WIDTH)
			p->w = DEFAULT_WINDOW_WIDTH;
		if (p->h < MIN_SIZE || p->h > MAX_HEIGHT)
			p->h = DEFAULT_WINDOW_HEIGHT;
	}
	else
	{
		p->w = DEFAULT_WINDOW_WIDTH;
		p->h = DEFAULT_WINDOW_HEIGHT;
	}
}

static void	int_res_set(char **argv, int argc, t_param *p)
{
	if (argc >= 5)
	{
		p->res = ft_atoi(argv[4]);
		if (p->res < 0.2 || p->res > 1.5)
			p->res = DEFAULT_RESOLUTION;
	}
	else
		p->res = DEFAULT_RESOLUTION;
	if (argc > 3 || argc == 2)
	{
		if (*argv[1] == 'J' || *argv[1] == 'j')
			p->f = &julia_set;
		else
			p->f = &mandlebrot_set;
	}
}

int	main(int argc, char **argv)
{
	t_param	param;
	int		error;

	// if (argc > 1 && *argv[1] == 'h')
	// 	return (args_help());
	if (argc == 1)
		return (args_help());
	init_size(argv, argc, &param);
	int_res_set(argv, argc, &param);
	error = generate_fractal(&param);
	if (error)
		ft_printf("ERROR, could not open window code:%d\n", error);
	return (0);
}