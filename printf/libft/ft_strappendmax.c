/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappendmax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:22:59 by aurban            #+#    #+#             */
/*   Updated: 2023/10/28 18:36:23 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description ---------------------------
Will append to dst until src is fully appended or dst is full
_______________________________________
Return --------------------------------
	size_t = -1 for Null strings
	Otherwise, the amount of appended char.
*/
size_t	ft_strappendmax(char *dst, const char *src, size_t offset, size_t max)
{
	size_t	i;
	size_t	write_size;

	if (!src || !dst)
		return (-1);
	if (max < offset)
		return (0);
	i = 0;
	write_size = max - offset;
	while (src[i] && i < write_size)
	{
		dst[offset + i] = src[i];
		i++;
	}
	return (i);
}
