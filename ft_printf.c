/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:45:36 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/11/18 23:46:27 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_printf_format(char f, va_list args, int *count)
{
    if (f == 'c')
        ft_putchar(va_arg(args, int), count);
    else if (f == '%')
        ft_putchar('%', count);
    else if (f == 's')
        ft_putstr(va_arg(args, char *), count);
    else if (f == 'd' || f == 'i')
        ft_putnbr(va_arg(args, int), count);
    else if (f == 'u')
        ft_unbr(va_arg(args, unsigned int), count);
    else if (f == 'x')
        ft_putnbr_base(va_arg(args, int), 16, "0123456789abcdef", count);
    else if (f == 'X')
        ft_putnbr_base(va_arg(args, int), 16, "0123456789ABCDEF", count);
    else if (f == '%')
        ft_putchar('%', count);
}

int	ft_printf(const char *s, ...)
{
    va_list args;
    int count;
    
    if (!s)
        return (-1);
    va_start(args, s);
    count = 0;
    while (*s)
    {
        if (*s == '%')
            ft_printf_format(*(++s), args, &count);
        else
            ft_putchar(*s, &count);
        s++;
    }
    va_end(args);
    return (count);
}

// int main()
// {
//     printf("cout = %d\n", ft_printf("hello %d  %s %x \n", 12345, " everyone", 444));
//     printf("cout = %d\n", printf("hello %d  %s %x \n", 12345, " everyone", 444));
//     return 0;
// }