/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:07:11 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:07:12 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*new_env(void *key, void *value)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	node->key = key;
	node->value = value;
	node->next = NULL;
	return (node);
}

void	queue_env(t_envl *env_lst, t_env *new)
{
	if (env_lst->head == NULL)
	{
		env_lst->head = new;
		env_lst->tail = new;
	}
	else
	{
		env_lst->tail->next = new;
		env_lst->tail = new;
	}
	env_lst->length++;
}
