/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 22:26:56 by lernst            #+#    #+#             */
/*   Updated: 2026/06/04 18:20:11 by lernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_address(unsigned long n)
{
	char	*base;
	char	c;
	int		len;

	base = "0123456789abcdef";
	len = 0;
	if (n > 15)
		len = put_address(n / 16);
	c = base[n % 16];
	write(1, &c, 1);
	return (len + 1);
}

int	ft_putptr(void *ptr)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (2 + put_address((unsigned long)ptr));
}
