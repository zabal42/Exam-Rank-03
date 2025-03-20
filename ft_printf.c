/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelzabal <mikelzabal@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:52:34 by mikelzabal        #+#    #+#             */
/*   Updated: 2025/03/20 13:12:33 by mikelzabal       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void    ft_putstr(char *s, int *count)
{
	if (!s)
		s = "(null)";
	while (*s)
		*count += write (1, s++, 1);
}
void    ft_putnbr(long n, int base, int *count)
{
	if (n < 0)
	{
		*count += write (1, "-", 1);
		n = -n;
	}
	if (n >= base)
		ft_putnbr(n / base, base, count);
	*count += write (1, &"0123456789abcdef"[n % base], 1);
}
int ft_printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 's')
				ft_putstr(va_arg(args, char*), &count);
			else if (*format == 'd')
				ft_putnbr(va_arg(args, int), 10, &count);
			else if (*format == 'x')
				ft_putnbr(va_arg(args, unsigned int), 16, &count);
		}
		else
			count += write (1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
