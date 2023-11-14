/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:57:51 by aurban            #+#    #+#             */
/*   Updated: 2023/11/13 16:12:29 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 450
#define DEFAULT_RESOLUTION 0.75
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

static void	set_size(char **argv, int argc, int *width, int *height)
{
	if (argc >= 3)
	{
		*width = ft_atoi(argv[2]);
		*height = ft_atoi(argv[3]);
		if (*width < MIN_SIZE || *width > MAX_WIDTH)
			*width = DEFAULT_WINDOW_WIDTH;
		if (*height < MIN_SIZE || *height > MAX_HEIGHT)
			*height = DEFAULT_WINDOW_HEIGHT;
	}
	else
	{
		*width = DEFAULT_WINDOW_WIDTH;
		*height = DEFAULT_WINDOW_HEIGHT;
	}
}

static void	set_reso_form(char **argv, int argc, float *reso, void **f)
{
	if (argc >= 5)
	{
		*reso = ft_atoi(argv[4]);
		if (*reso < 0.2 || *reso > 1.5)
			*reso = DEFAULT_RESOLUTION;
	}
	else
		*reso = DEFAULT_RESOLUTION;
	if (argc > 3 || argc == 2)
	{
		if (*argv[1] == 'J' || *argv[1] == 'j')
			*f = julia_set;
		else
			*f = mandlebrot_set;
	}
}

int	main(int argc, char **argv)
{
	int		width;
	int		height;
	float	resolution;
	void	*fformula;

	if (argc > 1 && *argv[1] == 'h')
		return (args_help());
	if (argc == 1)
		args_help();
	set_size(argv, argc, &width, &height);
	set_reso_form(argv, argc, &resolution, fformula);
	generate_fractal(fformula, width, height, resolution);
	return (0);
}