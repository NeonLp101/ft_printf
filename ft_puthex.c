/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:47:45 by lernst            #+#    #+#             */
/*   Updated: 2026/05/08 22:21:24 by lernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_puthex(unsigned int n, int uppercase)
{
	char	*base;
	char	c;
	int		len;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = 0;
	if (n > 15)
		len = ft_puthex(n / 16, uppercase);
	c = base[n % 16];
	write(1, &c, 1);
	return (len + 1);
}
