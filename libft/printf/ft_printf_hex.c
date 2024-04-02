/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:53:34 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/16 15:32:53 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_hex_low(unsigned long i)
{
	unsigned int	len;

	len = 0;
	if (i >= 16)
		len += ft_hex_low(i / 16);
	if (ft_printf_char("0123456789abcdef"[i % 16]) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_hex_up(unsigned long i)
{
	unsigned int	len;

	len = 0;
	if (i >= 16)
		len += ft_hex_up(i / 16);
	if (ft_printf_char("0123456789ABCDEF"[i % 16]) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_printf_hex(unsigned long i)
{
	unsigned int	len;

	len = 0;
	len += write(1, "0x", 2);
	len += ft_hex_low(i);
	return (len);
}
