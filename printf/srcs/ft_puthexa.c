/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:48:40 by tsadouk           #+#    #+#             */
/*   Updated: 2023/11/18 16:30:21 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned int	digits(unsigned int n)
{
	int	count;

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
	write(1, &"0123456789abcdef"[nb % 16], 1);
}

int	ft_puthexa(unsigned int nb)
{
	int	len;

	len = digits(nb);
	ft_putnbr(nb);
	return (len);
}
