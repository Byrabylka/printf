/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fooswyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:46:36 by fooswyn           #+#    #+#             */
/*   Updated: 2021/12/23 18:53:30 by fooswyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	k;

	k = ft_len(nb);
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * (-1));
	}
	else
	{
		if (nb >= 10)
			ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	return (k);
}

int	ft_putlnbr(void	*p)
{
	unsigned long	n;
	int				len;

	n = (unsigned long) p;
	len = 2;
	ft_putstr("0x");
	ft_puthex(n, "0123456789abcdef", &len);
	return (len);
}

void	ft_puthex(unsigned long n, char *base, int *len)
{
	if (n < 16 && n >= 0)
	{
		(*len) += ft_putchar(base[n]);
		return ;
	}
	ft_puthex(n / 16, base, len);
	ft_puthex(n % 16, base, len);
}

void	ft_putu(unsigned int n, int *len)
{
	if (n < 10)
	{
		(*len) += ft_putchar(n + '0');
		return ;
	}
	ft_putu(n / 10, len);
	ft_putu(n % 10, len);
}
