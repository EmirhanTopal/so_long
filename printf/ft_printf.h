/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:54:38 by marvin            #+#    #+#             */
/*   Updated: 2025/03/02 17:54:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_printf_strlen(const char *str);
int	ft_putnbr(long nbr);
int	ft_putstr(char *str);
int	ft_uputnbr(unsigned int nbr);
int	ft_pointer(void *p);
int	ft_puthexanbr(unsigned long long_nbr, char control);

#endif