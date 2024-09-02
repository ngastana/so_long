/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:20:50 by ngastana          #+#    #+#             */
/*   Updated: 2023/10/06 20:08:18 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# define DECIMAL "0123456789"
# define HEXBASEUPPER "0123456789ABCDEF"
# define HEXBASELOWER "0123456789abcdef"

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h> //va_list va_start va_arg va_end

int	ft_printf(char const *src, ...);
int	ft_num(long num, char *base, int len);
int	ft_word(char const *format, int i, va_list src);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_nup(size_t num, int len);

#endif