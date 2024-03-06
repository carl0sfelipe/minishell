/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:07:08 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:07:10 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_key(char *env_str)
{
	char	*key;
	char	*separator;
	size_t	len;

	separator = ft_strchr(env_str, '=');
	if (separator == NULL)
		return (NULL);
	len = separator - env_str;
	key = ft_substr(env_str, 0, len);
	return (key);
}

char	*get_value(char *env_str)
{
	char	*value;
	char	*separator;
	size_t	len;

	separator = ft_strchr(env_str, '=');
	if (separator == NULL)
		return (NULL);
	len = env_str + (ft_strlen(env_str) - 1) - separator;
	value = ft_substr(env_str, (separator + 1) - env_str, len);
	return (value);
}

void	create_env_list(t_envl *env_lst, char **envp)
{
	size_t	i;
	char	*key;
	char	*value;

	env_lst->head = NULL;
	env_lst->length = 0;
	i = 0;
	while (envp[i])
	{
		key = get_key(envp[i]);
		value = get_value(envp[i]);
		queue_env(env_lst, new_env(key, value));
		i++;
	}
}
