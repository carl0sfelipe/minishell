/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:08:47 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:08:49 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*remove_env(t_envl *env_lst, char *key)
{
	t_env	*tmp;
	t_env	*prev;

	tmp = env_lst->head;
	prev = NULL;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
		{
			if (prev == NULL)
				env_lst->head = tmp->next;
			else
			{
				if (tmp->next == NULL)
					env_lst->tail = prev;
				prev->next = tmp->next;
			}
			env_lst->length--;
			return (tmp);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (NULL);
}

int	unset(char **argv, t_envl *env_lst)
{
	char	*key;
	t_env	*tmp;
	size_t	i;

	i = 1;
	while (argv[i])
	{
		key = argv[i];
		tmp = remove_env(env_lst, key);
		if (tmp)
		{
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
		i++;
	}
	return (0);
}
