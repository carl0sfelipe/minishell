/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:08:53 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:08:54 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_operator(int c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	is_metachar(int c)
{
	return (ft_isspace(c) || is_operator(c));
}

int	is_quote(int c)
{
	return (c == '\"' || c == '\'');
}

void	init_index(t_index *i)
{
	i->key = 0;
	i->new = 0;
	i->old = 0;
	i->start = 0;
}

void	copy_char(char *new_content, char *content, t_index *i)
{
	new_content[i->new] = content[i->old];
	i->new++;
	i->old++;
}
