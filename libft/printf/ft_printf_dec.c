/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:22:32 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/16 15:32:17 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_printf_dec(long i)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(i);
	len = ft_printf_s(num);
	free(num);
	return (len);
}
