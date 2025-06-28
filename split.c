/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 23:46:01 by jaehlee           #+#    #+#             */
/*   Updated: 2025/06/21 23:46:01 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**free_all(char **list)
{
	int		i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (NULL);
}

static char	*make_char(char *s, int n)
{
	int		i;
	char	*word;

	i = 0;
	word = 0;
	if (n == 0)
		return (NULL);
	word = (char *)malloc(sizeof(char) * (n + 2));
	if (!word)
		return (NULL);
	while (i < n)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '/';
	word[i + 1] = '\0';
	return (word);
}

static int	word_count(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	**split2(char *s, char c)
{
	char	**result;
	int		i;
	int		k;
	int		save;

	i = 0;
	k = 0;
	result = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!result)
		return (NULL);
	while (i < word_count(s, c) && s[k] != '\0')
	{
		while (s[k] == c)
			k++;
		save = k;
		while (s[k] != c && s[k] != '\0')
			k++;
		result[i] = make_char(&s[save], k - save);
		if (result[i++] == 0)
			return (free_all(result));
	}
	result[i] = NULL;
	return (result);
}

void	error_msg(char *s, int i)
{
	perror(s);
	exit(i);
}
