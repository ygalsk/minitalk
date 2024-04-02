/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:10:58 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/16 15:29:33 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin_gnl(char *save, char *buf)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (save == NULL)
	{
		save = (char *)malloc(sizeof(char) * (1));
		save[0] = '\0';
	}
	if (!buf)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(save) + ft_strlen(buf)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (save)
		while (save[++i] != '\0')
			str[i] = save[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	str[ft_strlen(save) + ft_strlen(buf)] = '\0';
	free(save);
	return (str);
}
