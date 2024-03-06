/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:06:11 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:06:13 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*copy_s;
	size_t			len_s;
	unsigned int	i;

	len_s = ft_strlen(s);
	copy_s = malloc((len_s + 1) * sizeof(char));
	if (copy_s == NULL)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(copy_s + i) = *(s + i);
		i++;
	}
	*(copy_s + i) = '\0';
	return (copy_s);
}
