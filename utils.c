/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:49:14 by jaehlee           #+#    #+#             */
/*   Updated: 2025/06/24 17:49:14 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:57:35 by jaehlee           #+#    #+#             */
/*   Updated: 2025/06/24 16:57:35 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**path_maker(char  *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			return (split2((envp[i] + 5), ':'));
		i++;
	}
	return (NULL);
}

char	*check_cmd(char **path, char *cmd)
{
	int		i;
	char	*command;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (path[i])
	{
		command = ft_strjoin(path[i], cmd);
		if (access(command, X_OK) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

void	first_work(t_arg *arg, int *fd,  char *argv[],  char *envp[])
{
	arg->infile = open(argv[1], O_RDONLY, 0644);
	if (arg->infile == -1)
		perror("infile open error");
	arg->order1 = check_cmd(arg->path, arg->cmd1[0]);
	close (fd[0]);
	if (dup2(fd[1], 1) == -1)
		perror("dup error");
	close (fd[1]);
	close (arg->infile);
	if (execve(arg->order1, arg->cmd1, envp) == -1)
		perror("exec error");
}

void	second_work(t_arg *arg, int *fd,  char *argv[],  char *envp[])
{
	arg->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (arg->outfile == -1)
		perror("outfile open error");
	arg->order2 = check_cmd(arg->path, arg->cmd2[0]);
	close (fd[1]);
	if (dup2(arg->outfile, 1) == -1)
		perror("dup error");
	if (dup2(fd[0], 0) == -1)
		perror("dup error");
	close (fd[0]);
	close(arg->outfile);
	if (execve(arg->order2, arg->cmd2, envp) == -1)
		perror("exec error");
}

void	pipe_maker(t_arg *arg, char  *argv[], char  *envp[])
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];

	pipe(fd);
	pid1 = fork();
	if (pid1 == -1)
		perror("pid error");
	else if (pid1 == 0)
		first_work(arg, fd, argv, envp);
	else
	{
		pid2 = fork();
		if (pid2 == -1)
			perror("pid error");
		else if (pid2 == 0)
			second_work(arg, fd, argv, envp);
		else
		{
			close(fd[0]);
			close(fd[1]);
			waitpid(pid1, NULL, 0);
			waitpid(pid2, NULL, 0);
		}
	}
}
