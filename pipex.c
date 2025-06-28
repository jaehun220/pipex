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

int	main(int argc, char *argv[], char *envp[])
{
	t_arg	all;

	if (argc != 5)
		error_msg("input error", 1);
	pipe_maker(&all, argv, envp);
	return (0);
}
