/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:18:36 by ngastana          #+#    #+#             */
/*   Updated: 2023/12/28 20:47:59 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_word(char const *format, int i, va_list src)
{
	int		len;

	len = 0;
	if (format[i + 1] == 'c')
		len += ft_putchar((char)va_arg(src, int));
	else if (format[i + 1] == 's')
		len += ft_putstr(va_arg(src, char *));
	else if (format[i +1] == 'p')
		len += ft_putstr("0x") + ft_nup(va_arg(src, size_t), len);
	else if (format[i + 1] == 'd' || format[i +1] == 'i')
		len += ft_num(va_arg(src, int), DECIMAL, len);
	else if (format[i + 1] == 'u')
		len += ft_num(va_arg(src, unsigned int), DECIMAL, len);
	else if (format[i +1] == 'x')
		len += ft_num(va_arg(src, unsigned int), HEXBASELOWER, len);
	else if (format[i +1] == 'X')
		len += ft_num(va_arg(src, unsigned int), HEXBASEUPPER, len);
	else if (format[i +1] == '%')
		len += ft_putchar('%');
	return (len);
}

int	character(char s)
{
	if (s == 'c' || s == 's' || s == 'p' || s == 'd')
		return (1);
	else if (s == 'u' || s == 'x' || s == 'X' || s == '%')
		return (1);
	return (0);
}

int	ft_printf(char const *format, ...)
{
	va_list	src;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start (src, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len = len + ft_word (format, i, src) - 2;
			i = i + 2;
		}
		else
		{
			ft_putchar(format[i]);
			i++;
		}
	}
	return (i + len);
}
/*int	main(void)
{
	char	*s;
	char	*s1;
	char	c;
	void	*p;
	int		d;
	int		i;
	int		len;
	int		u;
	int		x;
	int		X;

	s = NULL;
	s1 = "hoy cae1";
	c = 'e';
	p = -109;
	d = -12444;
	i = -12444;
	u = -123532;
	x = 86674;
	X = 564224;
	ft_printf("resultaso s: %s \n\n", s);
	len = ft_printf("resultaso s1: %s esta vacio\n", s1);
	ft_printf("largura de el anterior: %i\n\n", len);
	len = ft_printf("resultado %%: %% \n");
	ft_printf("largura de el anterior: %i\n\n", len);
 

	len = ft_printf("resultado c: %c \n", c);
	ft_printf("largura de el anterior: %i\n\n", len);

	len = ft_printf("resulatdo p: %p \n", p);
	ft_printf("largura de el anterior: %i\n\n", len);

	len = ft_printf("resultado d: %d \n", d);
	ft_printf("largura de el anterior: %i\n\n", len);

	len = ft_printf("resultado i: %i \n", i);
	ft_printf("largura de el anterior: %i\n\n", len);

	len = ft_printf("resultado u: %u \n", u);
	ft_printf("largura de el anterior: %i\n\n", len);

	len = ft_printf("resultado x: %x \n", x);
	ft_printf("largura de el anterior: %i\n\n", len);

	len = ft_printf("resultado X: %X \n", X);
	ft_printf("largura de el anterior: %i\n\n", len);
	
	len = ft_printf("\001\002\007\v\010\f\r\n");
	ft_printf("largura de el anterior: %i\n\n", len);
} */