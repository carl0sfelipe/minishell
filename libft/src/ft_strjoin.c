/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:06:16 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:06:17 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_s = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (new_s == NULL)
		return (NULL);
	ft_memcpy(new_s, s1, len_s1 + 1);
	ft_memcpy(new_s + len_s1, s2, len_s2 + 1);
	return (new_s);
}
