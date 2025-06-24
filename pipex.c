/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:49:54 by jaehlee           #+#    #+#             */
/*   Updated: 2025/06/24 17:49:54 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	allfree(char **all)
{
	int	i;

	i = 0;
	while (all[i])
	{
		free(all[i]);
		i++;
	}
	free(all);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_arg	all;

	if (argc != 5)
		perror("input count");
	all.cmd1 = ft_split(argv[2], ' ');
	all.cmd2 = ft_split(argv[3], ' ');
	all.path = path_maker(envp);
	pipe_maker(&all, argv, envp);
	allfree(all.path);
	allfree(all.cmd1);
	allfree(all.cmd2);
	return (0);
}
