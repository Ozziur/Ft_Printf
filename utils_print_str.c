/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:29:33 by mruizzo           #+#    #+#             */
/*   Updated: 2022/01/29 22:00:57 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_spaces(int n, t_flag *flag)
{
	while (n > 0)
	{
		if (flag->zero)
			ft_putchar('0', flag);
		else
			ft_putchar(' ', flag);
		n--;
	}
}

char	*print_char(char *s, va_list args, t_flag *flag)
{
	char	ch;

	ch = va_arg(args, int);
	if (flag->width && !flag->minus)
	{
		print_spaces(flag->width - 1, flag);
		ft_putchar(ch, flag);
	}
	else if (flag->width && flag->minus)
	{
		ft_putchar(ch, flag);
		print_spaces(flag->width - 1, flag);
	}
	else
		ft_putchar(ch, flag);
	s++;
	return (s);
}
