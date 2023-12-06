/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:44:11 by tsadouk           #+#    #+#             */
/*   Updated: 2023/11/28 17:39:14 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/includes/ft_printf.h"
#include <signal.h>

/*
** Le serveur doit afficher le message envoyé par le client
*/
void	decrypt_message(int sig)
{
	static int		i = 0;
	static char		c = 0;

	if (sig == SIGUSR2)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("PID = %d\n", getpid());
	signal(SIGUSR1, decrypt_message);
	signal(SIGUSR2, decrypt_message);
	while (1)
		pause();
	return (0);
}
