/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:50:07 by aurban            #+#    #+#             */
/*   Updated: 2023/11/17 16:38:48 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define WIN_SMALLX 600
#define WIN_SMALLY 400
#define WIN_MEDIUMX 1200
#define WIN_MEDIUMY 800
#define WIN_LARGEX 2400
#define WIN_LARGEY 1600

static int	init_size(char *str, t_param *p)
{
	p->w = WIN_SMALLX;
	p->h = WIN_SMALLY;
	if (str)
	{
		if (!ft_strncmp(str, "medium", 6))
		{
			p->w = WIN_MEDIUMX;
			p->h = WIN_MEDIUMY;
		}
		else if (!ft_strncmp(str, "large", 5))
		{
			p->w = WIN_LARGEX;
			p->h = WIN_LARGEY;
		}
	}
	p->screen_resolution = (long double)1 / (p->h / 2);
	printf("resolution = %LF\n", p->screen_resolution);
	return (100);
}

static int	init_const(char *str, t_param *p)
{
	int	error;

	error = ft_atoz(&p->c, str);
	if (error)
	{
		p->set = 0;
		error_invalid_constant(error);
		return (10);
	}
	return (0);
}

static int	init_set(char *str, t_param *p)
{
	if (*str == 'M' || *str == 'm')
		p->set = 'M';
	else if (*str == 'J' || *str == 'j')
		p->set = 'J';
	else
	{
		p->set = 0;
		error_invalid_set(*str);
		return (1);
	}
	return (0);
}

/*
set  =  Fractal Set:  'M'= Mandlebrot 'J'= Julia"
const=  Fractal Const: xxixx (x are digits)"
size =  [small, medium, large] impacts rendering speed\n");
*/
int	init_param(char **argv, int argc, t_param *p)
{
	int	error;

	error = 0;
	while (argc-- > 1)
	{
		if (ft_strnstr(argv[argc], "set=", 4) != NULL)
			error += init_set(&argv[argc][4], p);
		else if (ft_strnstr(argv[argc], "const=", 6) != NULL)
			error += init_const(&argv[argc][6], p);
		else if (ft_strnstr(argv[argc], "size=", 5))
			error = init_size(&argv[argc][5], p);
		argc--;
	}
	if (error < 100)
		error += init_size(NULL, p);
	p->zoom = 1.0;
	printf("parse_error=%d\n", error);
	return (error - 100);
}
