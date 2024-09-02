/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:45:08 by ngastana          #+#    #+#             */
/*   Updated: 2023/10/06 19:55:45 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(char *base)
{
	size_t	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_num(long num, char *base, int len)
{
	int		baselen;

	baselen = ft_strlen(base);
	if (num < 0)
	{
		num = num * -1;
		len ++;
		ft_putchar('-');
	}
	if (num >= baselen)
	{
		len = ft_num((num / baselen), base, len);
	}
	len += ft_putchar(base[num % baselen]);
	return (len);
}
