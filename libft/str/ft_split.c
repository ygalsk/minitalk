/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:37:03 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/16 15:35:38 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

void	ft_free(char **substrs)
{
	int	i;

	i = 0;
	while (substrs[i])
	{
		free(substrs[i]);
		i++;
	}
	free(substrs);
}

void	ft_suballoc(char **substrs, char const *s, char c)
{
	char		**sub_strs;
	char const	*temp;

	sub_strs = substrs;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		temp = s;
		if (*s)
		{
			temp = s;
			while (*temp && *temp != c)
				temp++;
			*sub_strs = ft_substr(s, 0, temp - s);
			sub_strs++;
			if (!sub_strs)
				return ;
		}
		s = temp;
	}
	*sub_strs = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**substrs;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	substrs = (char **)malloc(sizeof(char *) * (count + 1));
	if (!substrs)
		return (NULL);
	ft_suballoc(substrs, s, c);
	return (substrs);
}
