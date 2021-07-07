/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:19:38 by ldurante          #+#    #+#             */
/*   Updated: 2021/07/07 20:20:09 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

size_t ft_strlen(char *str)
{
	size_t i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_numlen(long long n, int base_len)
{
	int i = 1;
	while (n >= base_len || n <= -base_len)
	{
		n = n / base_len;
		i++;
	}
	return (i);
}

void	ft_putnum(long long n, int base_len, char *base)
{
	if (n >= base_len)
		ft_putnum(n / base_len, base_len, base);
	write(1, &base[n % base_len], 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	char	*str, *base;
	int		i, n, base_len;
	long	digit;
	int		width = 0, preci = 0, point = 0, length = 0, zeros = 0, spaces = 0, sign = 0;
	
	va_start(list, format);
	i = -1;
	n = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			width = 0, preci = 0, point = 0, zeros = 0, spaces = 0, sign = 0, n = 0;
			while (format[i] >= '0' && format[i] <= '9')
			{
				width = width * 10 + (format[i] - 48);
				i++;
			}
			if (format[i] == '.')
			{
				i++;
				while (format[i] >= '0' && format[i] <= '9')
				{
					preci = preci * 10 + (format[i] - 48);
					i++;
				}
				point = 1;
			}
			if (format[i] == 's')
			{
				str = va_arg(list, char *);
				if (!str)
					str = "(null)";
				n = ft_strlen(str);
			}
			if (format[i] == 'd')
			{
				digit = va_arg(list, int);
				base = "0123456789";
				base_len = 10;
				if (digit < 0)
				{
					digit = -digit;
					sign = 1;
				}
				n = ft_numlen(digit, base_len) + sign;
			}
			if (format[i] == 'x')
			{
				digit = va_arg(list, unsigned);
				base = "0123456789abcdef";
				base_len = 16;
				n = ft_numlen(digit, base_len);
			}
			if (point && preci > n && format[i] != 's')
				zeros = preci - n + sign;
			else if (point && preci < n && format[i] == 's')
				n = preci;
			else if (point && !preci && (format[i] == 's' || digit == 0))
				n = 0;
			spaces = width - n - zeros;
			while (spaces-- > 0)
				length += write(1, " ", 1);
			if (sign)
				write(1, "-", 1);
			while (zeros-- > 0)
				length += write(1, "0", 1);
			if (format[i] == 's')
				write(1, str, n);
			else if (n > 0)
				ft_putnum(digit, base_len, base);
			length += n;
		}
		else
			length += write(1, &format[i], 1);
	}
	va_end(list);
	return (length);
}