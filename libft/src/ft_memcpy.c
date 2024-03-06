/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:05:42 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:05:43 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char		*temp_src;
	char			*temp_dst;
	unsigned int	i;

	temp_src = src;
	temp_dst = dst;
	i = 0;
	while (i < n)
	{
		*(temp_dst + i) = *(temp_src + i);
		i++;
	}
	return (dst);
}
