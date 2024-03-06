/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:55:27 by csiqueir          #+#    #+#             */
/*   Updated: 2024/03/06 18:55:40 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
char	*ft_ulltoa(unsigned long n, int base);
size_t	ft_nbrlen_base(unsigned long long n, int base);
char	*ft_handle_prefix(va_list p_arg, char *prefix);
void	ft_xtoupper(char *str);
#endif
