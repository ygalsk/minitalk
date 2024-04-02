/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 02:49:06 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/16 15:39:30 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*substr;
// 	size_t	i;
//
// 	i = 0;
// 	if (!s || (start >= ft_strlen(s)))
// 	{
// 		substr = (char *)malloc(1);
// 		if (!substr)
// 			return (NULL);
// 		substr[0] = '\0';
// 		return (substr);
// 	}
// 	substr = (char *)malloc(len + 1);
// 	if (!substr)
// 		return (NULL);
// 	while (s[start + i] && i < len)
// 	{
// 		substr[i] = s[start + i];
// 		i++;
// 	}
// 	substr[i] = '\0';
// 	return (substr)/ }
{
	size_t	slength;
	size_t	i;
	char	*substr;

	i = 0;
	slength = ft_strlen(s);
	if (!s)
		return (NULL);
	if (len > slength - start)
		len = slength - start;
	if (start >= slength)
		return (ft_strdup(""));
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
