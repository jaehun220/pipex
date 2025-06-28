/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:09:36 by jaehlee           #+#    #+#             */
/*   Updated: 2025/06/28 18:43:07 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include "./libft/libft.h"

typedef struct s_arg
{
	int		infile;
	int		outfile;
	char	**cmd1;
	char	**cmd2;
	char	**path;
	char	*order1;
	char	*order2;
}	t_arg;

char	**split2(char *s, char c);
char	**path_maker(char *envp[]);
char	*check_cmd(char **path, char *cmd);
void	first_work(t_arg *arg, int *fd, char *argv[], char *envp[]);
void	second_work(t_arg *arg, int *fd, char *argv[], char *envp[]);
void	pipe_maker(t_arg *arg, char *argv[], char *envp[]);
void	error_msg(char *s, int i);
char	**free_all(char **list);

#endif