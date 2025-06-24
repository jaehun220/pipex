/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:37:12 by jaehlee           #+#    #+#             */
/*   Updated: 2025/04/06 15:37:12 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	get_len(int n)
{
	int			len;

	len = 1;
	if (n == 0)
		return (1);
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			sign;
	int			len;
	char		*result;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	len = get_len(n);
	result = (char *)malloc(sizeof(char) * (len + sign + 1));
	if (!result)
		return (0);
	result[len + sign] = '\0';
	while (len--)
	{
		result[len + sign] = (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		result[0] = '-';
	return (result);
}
