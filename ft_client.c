/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:34:54 by tsadouk           #+#    #+#             */
/*   Updated: 2023/12/13 14:44:08 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <signal.h>

//  Le client prend en paramètre le PID du serveur et le message à envoyer
//  le client doit communiquer avec le serveur la chaine passe en paramètre
/*  Le client envoie un message chiffre au serveur sous forme binaire, 
	SIGUSR1 = 0, SIGUSR2 = 1. Le serveur affiche le message déchiffré.
	Chaque signal correspond à un bit du caractère. Il faudra donc envoyer 8
	signaux pour chaque caractère. 
*/

void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c >>= 1;
		i++;
		usleep(100);
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
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	return (0);
}
