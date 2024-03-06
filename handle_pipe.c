/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:54:58 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:07:42 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_pipe_io(int *pipefd, int *prevpipe)
{
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	dup2(*prevpipe, STDIN_FILENO);
	close(*prevpipe);
}

static void	set_output_to_prevpipe(int *pipefd, int *prevpipe)
{
	close(pipefd[1]);
	close(*prevpipe);
	*prevpipe = pipefd[0];
}

void	ft_pipe(char **argv, char **envp, t_envl *env_lst, int *prevpipe)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		set_pipe_io(pipefd, prevpipe);
		try_execute(argv, envp, env_lst);
		exit(0);
	}
	else
		set_output_to_prevpipe(pipefd, prevpipe);
}

void	ft_last(char **argv, char **envp, t_envl *env_lst, int *prevpipe)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		dup2(*prevpipe, STDIN_FILENO);
		close(*prevpipe);
		if (g_exit_status == 0)
			try_execute(argv, envp, env_lst);
		exit(g_exit_status);
	}
	else
	{
		close(*prevpipe);
		while (wait(&status) != -1)
			;
	}
	g_exit_status = WEXITSTATUS(status);
}
