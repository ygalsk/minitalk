/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:17:38 by dkremer           #+#    #+#             */
/*   Updated: 2024/03/22 19:07:30 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/libft.h"
#include <signal.h>

void	bit_to_ascii(int sig, siginfo_t *info, void *context)
{
	static unsigned char	byte;
	static int				i;

	(void)context;
	if (sig == SIGUSR1)
		byte |= (1 << i);
	i++;
	if (i == 8)
	{
		if (byte == 0)
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR2);
		}
		ft_printf("%c", byte);
		byte = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("ERROR");
		return (1);
	}
	ft_printf("SERVER PID: %d\n", getpid());
	sa.sa_sigaction = bit_to_ascii;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	(void)argv;
// 	if (argc != 1)
// 	{
// 		ft_printf("ERROR");
// 		return (1);
// 	}
// 	ft_printf("SERVER PID: %d\n", getpid());
// 	while (argc == 1)
// 	{
// 		signal(SIGUSR1, bit_to_ascii);
// 		signal(SIGUSR2, bit_to_ascii);
// 		pause();
// 	}
// 	return (0);
// }
