/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:16:41 by dkremer           #+#    #+#             */
/*   Updated: 2024/03/21 21:56:35 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/libft.h"
#include <signal.h>

void	msg_sent(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("MSG SENT!");
}

void	convertbit(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & (1 << i)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
			convertbit(pid, argv[2][i++]);
		signal(SIGUSR2, msg_sent);
		convertbit(pid, '\0');
	}
	else
	{
		ft_printf("ERROR");
		return (1);
	}
	return (0);
}
