/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:08:10 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:08:11 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(void)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	if (buf == NULL)
	{
		printf("minishell: pwd: %s\n", strerror(errno));
		exit(errno);
	}
	ft_putendl_fd(buf, STDOUT_FILENO);
	free(buf);
	exit(0);
}
