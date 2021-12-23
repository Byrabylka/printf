/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fooswyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:18:08 by aelousse          #+#    #+#             */
/*   Updated: 2021/12/23 18:39:32 by fooswyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_print(char c, va_list ptr, int *n);
int		ft_strlen(char *s);
int		ft_len(int nb);
int		ft_putchar(char c);
int		ft_putstr(char *s);
char	*ft_itoa(int n);
int		ft_putnbr(int n);
int		ft_putlnbr(void	*p);
void	ft_puthex(unsigned long n, char *base, int *len);
void	ft_putu(unsigned int n, int *len);

#endif
