/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:00:37 by jaehlee           #+#    #+#             */
/*   Updated: 2025/04/02 19:00:37 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	if (n[0] == '\0')
		return ((char *)h);
	needle_len = ft_strlen(n);
	i = 0;
	while (i < len && h[i])
	{
		j = 0;
		if (h[i + j] == n[j])
		{
			while (h[i + j] && n[j] && (i + j) < len)
			{
				if (h[i + j] != n[j])
					break ;
				if (j == needle_len - 1)
					return ((char *)h + i);
				j++;
			}
		}
		i++;
	}
	return (0);
}
