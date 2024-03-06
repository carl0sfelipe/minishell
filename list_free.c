/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:07:50 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:07:52 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env_list(t_envl *env_lst)
{
	t_env	*head;
	t_env	*tmp;

	head = env_lst->head;
	while (head)
	{
		tmp = head->next;
		free(head->key);
		free(head->value);
		free(head);
		head = tmp;
	}
}

void	free_token_list(t_tokenl *token_lst)
{
	t_token	*head;
	t_token	*tmp;

	head = token_lst->head;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
