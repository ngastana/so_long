/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:55:38 by ngastana          #+#    #+#             */
/*   Updated: 2023/10/06 20:09:21 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nup(size_t num, int len)
{
	if (num < 0)
		num = num * -1;
	if (num >= 16)
		len = ft_nup((num / 16), len);
	len += ft_putchar("0123456789abcdef"[num % 16]);
	return (len);
}
