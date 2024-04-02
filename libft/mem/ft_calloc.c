/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:19:26 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/16 15:30:15 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	i;
	unsigned int	ts;
	unsigned char	*bptr;
	void			*ptr;

	i = 0;
	ts = count * size;
	ptr = malloc(ts);
	if (ptr)
	{
		bptr = (unsigned char *)ptr;
		while (i < ts)
		{
			bptr[i] = 0;
			i++;
		}
	}
	return (ptr);
}
