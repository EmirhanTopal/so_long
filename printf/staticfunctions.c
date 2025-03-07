/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   staticfunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:55:12 by marvin            #+#    #+#             */
/*   Updated: 2025/03/02 18:02:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putnbr(long nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		len += ft_putnbr(nbr / 10);
	len += ft_putchar('0' + (nbr % 10));
	return (len);
}
