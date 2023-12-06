/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:24:21 by tsadouk           #+#    #+#             */
/*   Updated: 2023/11/18 16:57:39 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned int	digits(unsigned long long n)
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

static void	ft_putnbr(unsigned long long nb)
{
	if (nb > 15)
		ft_putnbr(nb / 16);
	write(1, &"0123456789abcdef"[nb % 16], 1);
}

int	ft_putptr(va_list ap)
{
	int		count;
	va_list	temp;

	count = 0;
	va_copy(temp, ap);
	if ((va_arg(temp, void *) == NULL))
	{
		count += ft_putstr("(nil)");
		va_end(temp);
		return (count);
	}
	va_end(temp);
	count += ft_putstr("0x");
	va_copy(temp, ap);
	count += digits(va_arg(ap, unsigned long long));
	ft_putnbr(va_arg(temp, unsigned long long ));
	va_end(temp);
	return (count);
}
