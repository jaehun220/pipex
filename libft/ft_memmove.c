/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:17:45 by jaehlee           #+#    #+#             */
/*   Updated: 2025/04/02 16:17:45 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char	*buf_src;
	unsigned char	*buf_dest;
	size_t			i;

	i = 0;
	buf_src = (unsigned char *) src;
	buf_dest = (unsigned char *) dest;
	if (buf_src == buf_dest || num == 0)
		return (dest);
	if (buf_dest < buf_src)
	{
		while (i < num)
		{
			buf_dest[i] = buf_src[i];
			i++;
		}
	}
	else
	{
		while (num--)
			buf_dest[num] = buf_src[num];
	}
	return (buf_dest);
}
