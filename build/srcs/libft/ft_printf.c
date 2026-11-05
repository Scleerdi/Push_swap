/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gshabait <gshabait@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/14 16:51:44 by gshabait      #+#    #+#                 */
/*   Updated: 2026/11/05 12:53:03 by gshabait      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printstr(char *s)
{
	if (!s)
		return (ft_putstr_fd("(null)", 1));
	return (ft_putstr_fd(s, 1));
}

static int	ft_printnmbr(int n)
{
	char	*str;
	int		count;

	str = ft_itoa(n);
	if (!str)
		return (0);
	count = ft_putstr_fd(str, 1);
	free(str);
	return (count);
}

static int	ft_print_pointer(void *ptr)
{
	unsigned long	address;
	int				count;

	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	address = (unsigned long)ptr;
	count = ft_putstr_fd("0x", 1);
	count += ft_printbase(address, "0123456789abcdef");
	return (count);
}

int	ft_format(va_list *args, char c)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(*args, int), 1));
	if (c == 's')
		return (ft_printstr(va_arg(*args, char *)));
	if (c == '%')
		return (ft_putchar_fd('%', 1));
	if (c == 'd' || c == 'i')
		return (ft_printnmbr(va_arg(*args, int)));
	if (c == 'u')
		return (ft_printbase(va_arg(*args, unsigned int), "0123456789"));
	if (c == 'x')
		return (ft_printbase(va_arg(*args, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_printbase(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	if (c == 'p')
		return (ft_print_pointer(va_arg(*args, void *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += ft_format(&args, format[i]);
		}
		else if (format[i] != '%')
			count += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
