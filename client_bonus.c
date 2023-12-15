/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:34:54 by tsadouk           #+#    #+#             */
/*   Updated: 2023/12/15 22:17:29 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_got_signal = 0;

void	signal_handler(int sig)
{
	if (sig == SIGUSR2)
		g_got_signal = 1;
}

void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_got_signal = 0;
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c >>= 1;
		i++;
		while (!g_got_signal)
			sleep(2);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_printf("Nombre d'arguments incorrect\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 0)
	{
		ft_printf("PID incorrect\n");
		return (1);
	}
	i = 0;
	signal(SIGUSR2, signal_handler);
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	return (0);
}
