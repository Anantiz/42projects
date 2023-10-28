/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_to_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:06:49 by aurban            #+#    #+#             */
/*   Updated: 2023/10/28 16:09:38 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_send_char(char *buffer, int *offset, char *ch)
{
	size_t	ncopied;
	
	ncopied = ft_strappendmax(buffer, ch, (size_t) offset, BUFSIZ);
	if (ncopied < 1)
	{
		flush(1, buffer, offset);
		send_char(buffer, offset, ch);
	}
}

void	ft_send_str(char *buffer, int *offset, char *str)
{
	size_t	ncopied;
	
	ncopied = ft_strappendmax(buffer, str, (size_t) offset, BUFSIZ);
	if (ncopied < ft_strlen(str))
	{
		flush(1, buffer, offset);
		send_str(buffer, offset, str + ncopied);
	}
}

void	ft_send_ptr(char *buffer, int *offset, void *ptr)
{
	char	*ptr_str;
	size_t	ncopied;

	ptr_str = ulltohex((unsigned long long) ptr);
	ncopied = ft_strappendmax(buffer, ptr_str, (size_t) offset, BUFSIZ);
	if (ncopied < ft_strlen(ptr_str))
	{
		ft_strappendmax(buffer, ptr_str + ncopied, (size_t) offset, BUFSIZ);
	}
	free(ptr_str);
}