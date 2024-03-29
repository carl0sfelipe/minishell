/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:07:55 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:07:58 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_lexer_state(t_lexer_state *state, char *input_copy)
{
	state->input = input_copy;
	state->curr = 0;
	state->is_word = FALSE;
	state->is_quoted = FALSE;
}

void	handle_exit(t_envl *env_lst, int status)
{
	free_env_list(env_lst);
	printf("exit\n");
	exit(status);
}

void	handle_exit_status(t_envl *env_lst)
{
	t_env	*tmp;

	tmp = get_env(env_lst, "?");
	if (tmp)
	{
		free(tmp->value);
		tmp->value = ft_itoa(g_exit_status);
	}
	else
		queue_env(env_lst, new_env(ft_strdup("?"), ft_strdup("0")));
	g_exit_status = 0;
}

int	main(int argc, char **argv, char **envp)
{
	char			*input;
	t_envl			env_lst;
	t_tokenl		token_lst;
	t_lexer_state	lexer_state;

	(void)argc;
	(void)argv;
	set_signal_handler_parent();
	create_env_list(&env_lst, envp);
	while (42)
	{
		handle_exit_status(&env_lst);
		input = readline("minishell$ ");
		if (input == NULL)
			handle_exit(&env_lst, 0);
		add_history(input);
		init_lexer_state(&lexer_state, ft_strdup(input));
		tokenize_input(&token_lst, input, &lexer_state);
		if (parse_tokens(&token_lst, &env_lst) == 0)
			handle_execution(&token_lst, &env_lst);
		free(input);
		free(lexer_state.input);
	}
	return (0);
}
