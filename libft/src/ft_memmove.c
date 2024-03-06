/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:05:44 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:05:45 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*temp_dst;
	const char	*temp_src;

	temp_dst = dst;
	temp_src = src;
	if (temp_dst < temp_src)
		ft_memcpy(dst, src, len);
	else
	{
		temp_dst += (len - 1);
		temp_src += (len - 1);
		while (len--)
			*temp_dst-- = *temp_src--;
	}
	return (dst);
}
