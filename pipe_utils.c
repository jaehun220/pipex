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

#include "pipex.h"

char	**path_maker(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split((envp[i] + 5), ':'));
		i++;
	}
	return (NULL);
}

char	*check_cmd(char **path, char *cmd)
{
	int		i;
	char	*temp;
	char	*command;

	if (!cmd || !*cmd)
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (path && path[i])
	{
		temp = ft_strjoin(path[i], "/");
		command = ft_strjoin(temp, cmd);
		free(temp);
		if (access(command, X_OK) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

void	first_work(t_arg *arg, int *fd, char *argv[], char *envp[])
{
	close (fd[0]);
	arg->infile = open(argv[1], O_RDONLY);
	if (arg->infile == -1)
		error_msg("infile open error", 1);
	arg->cmd1 = ft_split(argv[2], ' ');
	arg->path = path_maker(envp);
	arg->order1 = check_cmd(arg->path, arg->cmd1[0]);
	if (arg->order1 == NULL)
	{
		arg->path = free_all(arg->path);
		arg->cmd1 = free_all(arg->cmd1);
		error_msg("order error", 127);
	}
	if (dup2(arg->infile, 0) == -1)
		error_msg("dup error", 1);
	if (dup2(fd[1], 1) == -1)ㅋ
		error_msg("dup error", 1);
	close (fd[1]);
	close (arg->infile);
	execve(arg->order1, arg->cmd1, envp);
	arg->path = free_all(arg->path);
	arg->cmd1 = free_all(arg->cmd1);
	free (arg->order1);
	error_msg("exec error", 127);
}

void	second_work(t_arg *arg, int *fd, char *argv[], char *envp[])
{
	close (fd[1]);
	arg->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (arg->outfile == -1)
		error_msg("outfile open error", 1);
	arg->cmd2 = ft_split(argv[3], ' ');
	arg->path = path_maker(envp);
	arg->order2 = check_cmd(arg->path, arg->cmd2[0]);
	if (arg->order2 == NULL)
	{
		arg->path = free_all(arg->path);
		arg->cmd2 = free_all(arg->cmd2);
		error_msg("order error", 127);
	}
	if (dup2(arg->outfile, 1) == -1)
		error_msg("dup error", 1);
	if (dup2(fd[0], 0) == -1)
		error_msg("dup error", 1);
	close (fd[0]);
	close(arg->outfile);
	execve(arg->order2, arg->cmd2, envp);
	arg->path = free_all(arg->path);
	arg->cmd2 = free_all(arg->cmd2);
	free(arg->order2);
	error_msg("exec error", 127);
}

void	pipe_maker(t_arg *arg, char *argv[], char *envp[])
{
	pid_t	pid1;
	pid_t	pid2;
	int		status;
	int		fd[2];

	pipe(fd);
	pid1 = fork();
	if (pid1 == -1)
		error_msg("pid error", 1);
	else if (pid1 == 0)
		first_work(arg, fd, argv, envp);
	pid2 = fork();
	if (pid2 == -1)
		error_msg("pid error", 1);
	else if (pid2 == 0)
		second_work(arg, fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	else
		exit(EXIT_FAILURE);
}
