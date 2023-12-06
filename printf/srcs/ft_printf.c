/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:27:16 by tsadouk           #+#    #+#             */
/*   Updated: 2023/11/28 17:48:01 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_variables(va_list ap, char type)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (type == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (type == 'p')
		count += ft_putptr(ap);
	else if (type == 'd' || type == 'i')
		count += ft_putdecimal(va_arg(ap, int));
	else if (type == 'u')
		count += ft_putunsigned(va_arg(ap, unsigned int));
	else if (type == 'x')
		count += ft_puthexa(va_arg(ap, unsigned int));
	else if (type == 'X')
		count += ft_putbighexa(va_arg(ap, unsigned int));
	else if (type == '%')
		count += ft_putchar('%');
	else
	{
		count += ft_putchar('%');
		count += ft_putchar(type);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_variables(ap, *(++format));
		else
			count += write(1, format, 1);
		format++;
	}
	return (count);
}
