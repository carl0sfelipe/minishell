/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:07:00 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:07:02 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_append_syntax(t_token *curr, t_token *prev)
{
	if (prev == NULL || curr->next->next == NULL
		|| curr->next->label != OUT || prev->label != WORD)
	{
		printf("minishell: syntax error near unexpected token `>>'\n");
		return (2);
	}
	return (0);
}

int	handle_heredoc_syntax(t_token *curr, t_token *prev)
{
	if (prev == NULL || curr->next->next == NULL
		|| curr->next->next->label != WORD || prev->label != WORD)
	{
		printf("minishell: syntax error near unexpected token `<<'\n");
		return (2);
	}
	return (0);
}

int	check_syntax(t_tokenl *token_lst)
{
	t_token	*curr;
	t_token	*prev;

	prev = NULL;
	curr = token_lst->head;
	while (curr)
	{
		if (curr->label == PIPE || curr->label == IN || curr->label == OUT)
		{
			if (prev == NULL || curr->next == NULL
				|| curr->next->label != WORD
				|| prev->label != WORD)
			{
				printf("minishell: syntax error\n");
				return (2);
			}
		}
		else if (curr->label == APPEND)
			return (handle_append_syntax(curr, prev));
		else if (curr->label == HEREDOC)
			return (handle_heredoc_syntax(curr, prev));
		prev = curr;
		curr = curr->next;
	}
	return (0);
}
