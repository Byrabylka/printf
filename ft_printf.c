/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fooswyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:39:00 by fooswyn           #+#    #+#             */
/*   Updated: 2021/12/23 18:25:11 by fooswyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(char c, va_list ptr, int *k)
{
	if (c == '%')
		(*k) += ft_putchar('%');
	else if (c == 'c')
		(*k) += ft_putchar(va_arg(ptr, int));
	else if (c == 's')
		(*k) += ft_putstr(va_arg(ptr, char *));
	else if (c == 'd' || c == 'i')
		(*k) += ft_putnbr(va_arg(ptr, int));
	else if (c == 'p')
		(*k) += ft_putlnbr(va_arg(ptr, void *));
	else if (c == 'u')
		ft_putu(va_arg(ptr, unsigned int), k);
	else if (c == 'x')
		ft_puthex(va_arg(ptr, unsigned int), "0123456789abcdef", k);
	else if (c == 'X')
		ft_puthex(va_arg(ptr, unsigned int), "0123456789ABCDEF", k);
}

int	ft_printf(const char *format, ...)
{
	int		n;
	va_list	ptr;

	n = 0;
	va_start(ptr, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			ft_print(*format, ptr, &n);
		}
		else
			n += ft_putchar(*format);
		format++;
	}
	va_end(ptr);
	return (n);
}
