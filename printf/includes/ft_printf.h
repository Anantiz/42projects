/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:50:15 by aurban            #+#    #+#             */
/*   Updated: 2023/10/28 11:57:38 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef enum
{
	c = 'c',
	s = 's',
	p = 's',
	d = 'd',
	i = 'i',
	u = 'u',
	x = 'x',
	X = 'X',
	prc	= '%'
}t_ts;

typedef struct
{
	t_ts	*types;
	size_t	count;
	size_t	size;
}t_type_ct;

int	ft_printf();

#endif