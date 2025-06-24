/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:11:58 by jaehlee           #+#    #+#             */
/*   Updated: 2025/04/08 15:11:58 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned	int, char))
{
	unsigned int	len;
	unsigned int	index;
	char			*result;

	index = 0;
	result = 0;
	len = (unsigned int)(ft_strlen(s));
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (0);
	while (index < len)
	{
		result[index] = f(index, s[index]);
		index++;
	}
	result[index] = '\0';
	return (result);
}
