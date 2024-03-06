/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:06:37 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:06:38 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *s)
{
	unsigned int	i;
	unsigned int	i_mirror;
	char			temp;
	size_t			len_s;

	len_s = ft_strlen(s);
	i = 0;
	while (i < (len_s / 2))
	{
		i_mirror = (len_s - 1) - i;
		temp = *(s + i);
		*(s + i) = *(s + i_mirror);
		*(s + i_mirror) = temp;
		i++;
	}
}
