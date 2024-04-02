/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:22:07 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/16 15:32:38 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_printf_formats(char str, va_list args)
{
	int	len;

	len = 0;
	if (str == '\0')
		return (-1);
	if (str == '%')
		return (ft_printf_char('%'));
	if (str == 'c')
		return (ft_printf_char(va_arg(args, int)));
	if (str == 's')
		return (ft_printf_s(va_arg(args, char *)));
	if (str == 'p')
		return (ft_printf_hex(va_arg(args, unsigned long)));
	if (str == 'd' || str == 'i')
		return (ft_printf_dec(va_arg(args, int)));
	if (str == 'u')
		return (ft_printf_dec(va_arg(args, unsigned int)));
	if (str == 'x')
		return (ft_hex_low(va_arg(args, unsigned int)));
	if (str == 'X')
		return (ft_hex_up(va_arg(args, unsigned int)));
	return (len);
}
