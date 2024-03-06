/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_queue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:08:41 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:08:42 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*new_token(void *content, enum e_label label)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->content = content;
	token->label = label;
	token->next = NULL;
	return (token);
}

void	queue_token(t_tokenl *token_lst, t_token *new)
{
	if (token_lst->head == NULL)
	{
		token_lst->head = new;
		token_lst->tail = new;
		token_lst->length = 0;
		token_lst->pipe_count = 0;
	}
	else
	{
		token_lst->tail->next = new;
		token_lst->tail = new;
	}
	token_lst->length++;
	if (new->label == PIPE)
		token_lst->pipe_count++;
}

t_token	*dequeue_token(t_tokenl *token_lst)
{
	t_token	*head;

	head = token_lst->head;
	if (head->label == PIPE)
		token_lst->pipe_count--;
	if (token_lst->length > 1)
	{
		token_lst->head = head->next;
		head->next = NULL;
	}
	else
	{
		token_lst->head = NULL;
		token_lst->tail = NULL;
	}
	token_lst->length--;
	return (head);
}
