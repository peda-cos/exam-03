/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:17:14 by peda-cos          #+#    #+#             */
/*   Updated: 2025/02/08 13:24:54 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i += ft_putchar(str[i]);
	return (i);
}

static int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		i += ft_putnbr(n / 10);
	i += ft_putchar(n % 10 + '0');
	return (i);
}

static int	ft_puthex(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 15)
		i += ft_puthex(n / 16);
	if (n % 16 < 10)
		i += ft_putchar(n % 16 + '0');
	else
		i += ft_putchar(n % 16 - 10 + 'a');
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (format[i] == 'd')
				count += ft_putnbr(va_arg(args, int));
			else if (format[i] == 'x')
				count += ft_puthex(va_arg(args, unsigned int));
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
