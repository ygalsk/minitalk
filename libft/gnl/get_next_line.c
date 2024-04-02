/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:01:11 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/16 15:29:42 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*read_line(int fd, char *nx_line)
{
	char	*buff;
	ssize_t	err_check;

	buff = malloc(sizeof(buff) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	err_check = 1;
	while (!ft_strchr(nx_line, '\n') && err_check)
	{
		err_check = read(fd, buff, BUFFER_SIZE);
		if (err_check == -1)
		{
			free(buff);
			free(nx_line);
			return (NULL);
		}
		buff[err_check] = '\0';
		nx_line = ft_strjoin_gnl(nx_line, buff);
	}
	free(buff);
	return (nx_line);
}

char	*ft_nx_line(char *nx_line)
{
	char	*new;
	int		i;

	i = ft_len_nl(nx_line);
	if (!nx_line)
		return (NULL);
	if (nx_line[i] == '\n')
		new = (char *)malloc(sizeof(char) * (i + 2));
	else
		new = (char *)malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (nx_line[i] && nx_line[i] != '\n')
	{
		new[i] = nx_line[i];
		i++;
	}
	if (nx_line[i] == '\n')
	{
		new[i] = nx_line[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_leftover(char *nx_line)
{
	int		i;
	int		j;
	char	*new;

	if (!nx_line)
		return (NULL);
	i = ft_len_nl(nx_line);
	if (!nx_line[i])
	{
		free(nx_line);
		return (NULL);
	}
	new = (char *)malloc(sizeof(*new) * (ft_strlen(nx_line) - i + 1));
	if (!new)
		return (NULL);
	if (nx_line[i] == '\n')
		i++;
	j = 0;
	while (nx_line[i])
		new[j++] = nx_line[i++];
	new[j] = '\0';
	free(nx_line);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*nx_line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_line(fd, save);
	if (!save)
		return (NULL);
	nx_line = ft_nx_line(save);
	save = ft_leftover(save);
	if (nx_line[0] == '\0')
	{
		free(save);
		save = NULL;
		free(nx_line);
		return (NULL);
	}
	return (nx_line);
}
