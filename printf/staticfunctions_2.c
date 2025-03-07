/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   staticfunctions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:55:12 by marvin            #+#    #+#             */
/*   Updated: 2025/03/02 18:01:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (str == NULL)
	{
		len += ft_putstr("(null)");
		return (len);
	}
	while (str[i] != '\0')
	{
		len += ft_putchar(str[i]);
		i++;
	}
	return (len);
}

int	ft_uputnbr(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr > 9)
		len += ft_uputnbr(nbr / 10);
	len += ft_putchar('0' + (nbr % 10));
	return (len);
}

int	ft_pointer(void *p)
{
	int	len;

	len = 0;
	if (p == 0)
	{
		len += ft_putstr("(nil)");
		return (len);
	}
	len += ft_putstr("0x");
	len += ft_puthexanbr((unsigned long)p, 'x');
	return (len);
}

int	ft_puthexanbr(unsigned long long_nbr, char control)
{
	char	*x;
	char	*b_x;
	int		len;

	x = "0123456789abcdef";
	b_x = "0123456789ABCDEF";
	len = 0;
	if (control == 'x')
	{
		if (long_nbr >= 16)
			len += ft_puthexanbr(long_nbr / 16, 'x');
		len += ft_putchar(x[long_nbr % 16]);
	}
	else if (control == 'X')
	{
		if (long_nbr >= 16)
			len += ft_puthexanbr(long_nbr / 16, 'X');
		len += ft_putchar(b_x[long_nbr % 16]);
	}
	return (len);
}
