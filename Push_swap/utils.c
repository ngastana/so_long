/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:18:49 by ngastana          #+#    #+#             */
/*   Updated: 2024/03/06 10:40:38 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*a;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		a = "";
		return (a);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	a = malloc((len +1) * sizeof(char));
	if (a == NULL)
		return (0);
	while (s[start] != '\0' && len > 0)
	{
		len--;
		a[i] = s[start];
		i++;
		start++;
	}
	a[i] = '\0';
	return (a);
}

long	atoi_long(char *str)
{
	long	i;
	int		n;
	long	nb;

	i = 0;
	n = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] < 14 && str[i] > 8))
		i++;
	while (str[i] == '+' && (str[i +1] != ' ' && str[i +1] != '-'))
		i++;
	if (str[i] == '-')
	{
		i++;
		n = n * -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (str[i] - '0') + (nb * 10);
		i++;
	}
	return ((long)(nb * n));
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*str2;
	char			*str3;

	str2 = (char *) src;
	str3 = (char *) dest;
	i = 0;
	if (str2 == str3 || n == 0)
		return (dest);
	while (i < n)
	{
		str3[i] = str2[i];
		i++;
	}
	dest = str3;
	return (dest);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	char			*str1;
	char			*str2;

	i = 0;
	str1 = (char *)dst;
	str2 = (char *)src;
	if (str2 == str1 || len == 0)
		return (str1);
	if (str2 < str1)
	{
		i = len;
		while (i-- > 0)
			str1[i] = str2[i];
		return (str1);
	}
	else
	{
		str1 = ft_memcpy(dst, src, len);
	}
	dst = str1;
	return (dst);
}
