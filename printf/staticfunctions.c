#include "ft_printf.h"

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}
int ft_printf_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}
int ft_putnbr(long nbr)
{
    int len = 0;

    if (nbr < 0)
    {
        len += ft_putchar('-');
        nbr = -nbr;
    }
    if (nbr > 9)
    {
        len += ft_putnbr(nbr / 10);
    }
    len += ft_putchar('0' + (nbr % 10));
    return (len);
}

int ft_putstr(char *str)
{
    int i;
    int len;

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

int ft_uputnbr(unsigned int nbr)
{
    int len = 0;

    if (nbr > 9)
    {
        len += ft_uputnbr(nbr / 10);
    }
    len += ft_putchar('0' + (nbr % 10));
    return (len);
}

int ft_pointer(void *p)
{
    int len;

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

int ft_puthexanbr(unsigned long long_nbr, char control)
{
    char *x;
    char *X;
    int len;

    x = "0123456789abcdef";
    X = "0123456789ABCDEF";
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
        len += ft_putchar(X[long_nbr % 16]);
    }
    return (len);
}

