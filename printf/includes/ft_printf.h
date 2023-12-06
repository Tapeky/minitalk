/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:25:32 by tsadouk           #+#    #+#             */
/*   Updated: 2023/11/28 17:47:17 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_putchar(char c);
int				ft_putptr(va_list ap);
int				ft_puthexa(unsigned int nb);
int				ft_putbighexa(unsigned int nb);
int				ft_putdecimal(int nb);
int				ft_putunsigned(unsigned int nb);
int				ft_putstr(const char *s);
int				ft_printf(const char *format, ...);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *str);
#endif