/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:07:38 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:07:39 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	deep_free(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}

void	handle_execution(t_tokenl *token_lst, t_envl *env_lst)
{
	char	**argv;
	char	**envp;
	int		prevpipe;
	int		bkp_stdout;

	prevpipe = dup(STDIN_FILENO);
	bkp_stdout = dup(STDOUT_FILENO);
	while (token_lst->head)
	{
		envp = list_to_envp(env_lst);
		argv = get_next_argv(token_lst);
		if (token_lst->head)
			bkp_stdout = handle_redirect(token_lst, &prevpipe);
		env_lst = handle_builtin_pp(argv, envp, env_lst);
		if (token_lst->pipe_count > 0)
		{
			ft_pipe(argv, envp, env_lst, &prevpipe);
			free(dequeue_token(token_lst));
		}
		else
			ft_last(argv, envp, env_lst, &prevpipe);
		dup2(bkp_stdout, STDOUT_FILENO);
		deep_free(envp);
		deep_free(argv);
	}
}
