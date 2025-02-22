#include "ft_printf.h"

static int printf_control(char control, va_list args)
{
    int len;

    len = 0;
    if (control == 'd' || control == 'i')
        len += ft_putnbr(va_arg(args, int));
    else if (control == 'c')
        len += ft_putchar(va_arg(args, int));
    else if (control == 's')
        len += ft_putstr(va_arg(args, char *));
    else if (control == 'u')
        len += ft_uputnbr(va_arg(args, int));
    else if (control == 'p')
        len += ft_pointer(va_arg(args, void *));
    else if (control == 'x')
        len += ft_puthexanbr(va_arg(args, unsigned int), control);
    else if (control == 'X')
        len += ft_puthexanbr(va_arg(args, unsigned int), control);
    return (len);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int i;
    int len;

    va_start(args, format);
    i = 0;
    len = 0;
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            len += printf_control(format[i + 1], args);
            if(format[i + 1] == '%')
                len += ft_putchar('%');
            i++;
        }
        else
            len += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (len);
}
