/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:07:03 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:07:07 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(int argc, char **argv)
{
	size_t		i;
	enum e_bool	end_nl;

	end_nl = TRUE;
	if (argc > 1)
	{
		i = 1;
		if (ft_strcmp(argv[i], "-n") == 0)
		{
			end_nl = FALSE;
			i++;
		}
		while (argv[i])
		{
			ft_putstr_fd(argv[i], STDOUT_FILENO);
			if (argv[i + 1])
				ft_putchar_fd(' ', STDOUT_FILENO);
			i++;
		}
	}
	if (end_nl == TRUE)
		ft_putchar_fd('\n', STDOUT_FILENO);
	exit(0);
}
