/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:06:08 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:06:09 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*u_s1;
	unsigned char	*u_s2;
	int				i;

	u_s1 = (unsigned char *)s1;
	u_s2 = (unsigned char *)s2;
	i = 0;
	while (*(s1 + i) || *(s2 + i))
	{
		if (*(u_s1 + i) != *(u_s2 + i))
			return (*(u_s1 + i) - *(u_s2 + i));
		i++;
	}
	return (0);
}
