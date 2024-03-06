/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:05:48 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 19:05:50 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nbrlen_base(unsigned long long n, int base)
{
	size_t	len;

	len = 0;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_ulltoa(unsigned long n, int base)
{
	const char		*symbols;
	char			*buffer;
	size_t			len_n;
	unsigned int	i;

	if (n == 0)
		return (ft_strdup("0"));
	symbols = "0123456789abcdef";
	len_n = ft_nbrlen_base(n, base);
	buffer = malloc((len_n + 1) * sizeof(char));
	i = 0;
	while (n > 0)
	{
		*(buffer + i) = symbols[n % base];
		n /= base;
		i++;
	}
	*(buffer + i) = '\0';
	ft_strrev(buffer);
	return (buffer);
}

void	ft_xtoupper(char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str + i))
	{
		if (ft_isalpha(*(str + i)))
			*(str + i) -= (char)('a' - 'A');
		i++;
	}
}

char	*ft_handle_prefix(va_list p_arg, char *prefix)
{
	char	*buffer;

	buffer = ft_ulltoa(va_arg(p_arg, unsigned long), 16);
	ft_putstr_fd(prefix, 1);
	return (buffer);
}
