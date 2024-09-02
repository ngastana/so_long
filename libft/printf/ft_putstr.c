/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:17:33 by ngastana          #+#    #+#             */
/*   Updated: 2023/10/05 20:44:49 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	j;
	int	len;

	j = 0;
	len = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[j])
	{
		write(1, &s[j], 1);
		len++;
		j++;
	}
	return (len);
}
