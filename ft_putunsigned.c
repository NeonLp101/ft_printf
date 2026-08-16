/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:55:01 by lernst            #+#    #+#             */
/*   Updated: 2026/05/08 20:29:11 by lernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putunsigned(unsigned int n)
{
	char	c;
	int		len;

	len = 0;
	if (n > 9)
		len = ft_putunsigned(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	return (len + 1);
}
