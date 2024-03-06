/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:06:49 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:06:50 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char	*ft_read_file(int fd, char *temp)
{
	char	*content;
	char	*buffer;
	ssize_t	n;

	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	while (1)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n <= 0)
			break ;
		*(buffer + n) = '\0';
		content = ft_strjoin(temp, buffer);
		free(temp);
		temp = ft_strdup(content);
		free(content);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	if (ft_strlen(temp) == 0 || buffer == NULL)
	{
		free(temp);
		return (NULL);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char		*temp;
	char			*line;
	char			*n_line;
	char			*after_nl;

	if (temp == NULL)
		temp = ft_strdup("");
	temp = ft_read_file(fd, temp);
	if (temp == NULL)
		return (NULL);
	n_line = ft_strchr(temp, '\n');
	if (n_line)
	{
		after_nl = ft_strdup(n_line + 1);
		line = ft_substr(temp, 0, (n_line - temp) + 1);
	}
	else
	{
		after_nl = ft_strdup("");
		line = ft_strdup(temp);
	}
	free(temp);
	temp = ft_strdup(after_nl);
	free(after_nl);
	return (line);
}
