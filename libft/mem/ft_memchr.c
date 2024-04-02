/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:25:35 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/16 15:30:28 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned char	un_c;
	unsigned char	*p_s;

	un_c = (unsigned char)c;
	p_s = (unsigned char *)s;
	while (n > 0)
	{
		if (*p_s == un_c)
			return ((void *)p_s);
		p_s++;
		n--;
	}
	return (0);
}
