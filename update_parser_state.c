/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_parser_state.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:08:50 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:08:52 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_parser_state(char *content, size_t i, t_parser_state *state)
{
	if (content[i] == content[0])
	{
		if (state->prevent_default == FALSE)
			state->prevent_default = TRUE;
		else
			state->prevent_default = FALSE;
	}
	if (content[i] == '\'')
	{
		if (state->prevent_expand == FALSE)
			state->prevent_expand = TRUE;
		else
			state->prevent_expand = FALSE;
	}
}
