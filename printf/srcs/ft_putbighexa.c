/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbighexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:57:51 by tsadouk           #+#    #+#             */
/*   Updated: 2023/11/18 16:47:50 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned int	digits(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (!n)
		return (1);
	while (n > 0)
	{
		count++;
		n /= 16;
	}
	return (count);
}

static void	ft_putnbr(unsigned int nb)
{
	if (nb > 15)
		ft_putnbr(nb / 16);
	write(1, &"0123456789ABCDEF"[nb % 16], 1);
}

int	ft_putbighexa(unsigned int nb)
{
	int	len;

	len = digits(nb);
	ft_putnbr(nb);
	return (len);
}
