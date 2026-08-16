/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:21:21 by lernst            #+#    #+#             */
/*   Updated: 2026/06/06 18:51:32 by lernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dispatch(char spec, va_list *args)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (spec == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(*args, int, base)));
	if (spec == 'u')
		return (ft_putunsigned(va_arg(*args, unsigned int)));
	if (spec == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), 0, char *base_hex));
	if (spec == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), 1));
	if (spec == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	if (spec == '%')
		return (ft_putchar('%'));
	if (spec == 'a')
    return (ft_putstr("My awesome"));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;
	int		i;

	total = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			total += dispatch(format[i], &args);
		} 
		else
			total += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (total);
}
