#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int ft_printf(const char *format, ...);
int ft_putchar(char c);
int ft_printf_strlen(const char *str);
int ft_putnbr(long nbr);
int ft_putstr(char *str);
int ft_uputnbr(unsigned int nbr);
int ft_pointer(void *p);
int ft_puthexanbr(unsigned long long_nbr, char control);

#endif