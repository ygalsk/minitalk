/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:24:31 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/16 15:29:03 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_numlen(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(long n)
{
	char			*str;
	int				len;
	unsigned int	num;

	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)malloc(ft_numlen(n) + 1);
	if (!str)
		return (NULL);
	len = ft_numlen(n);
	num = n;
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	str[len] = '\0';
	while (num > 0)
	{
		len--;
		str[len] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
