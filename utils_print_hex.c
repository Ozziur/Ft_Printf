/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:57:52 by mruizzo           #+#    #+#             */
/*   Updated: 2022/02/01 17:52:21 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_ptr(unsigned long num, char *base, t_flag *flag)
{
	char	result[18];
	int		i;

	i = 1;
	while (num)
	{
		result[i] = base[num % 16];
		num = num / 16;
		i++;
	}
	i--;
	if (i)
		ft_putstr("0x", flag);
	while (i)
	{
		ft_putchar(result[i], flag);
		i--;
	}
}

char	*print_pointer(char *s, va_list args, t_flag *flag)
{
	void	*ptr;
	int		n_symbol;

	ptr = va_arg(args, void *);
	n_symbol = len_num_hex((unsigned long)ptr);
	if (flag->plus || flag->space)
		n_symbol++;
	if (flag->accuracy > n_symbol)
		n_symbol = flag->accuracy;
	if (flag->width && !flag->minus)
		print_spaces(flag->width - n_symbol - 2, flag);
	if (ptr == 0)
		ft_putstr("0x0", flag);
	else
		ft_putnbr_ptr((unsigned long)ptr, "0123456789abcdef", flag);
	if (flag->width && flag->minus)
		print_spaces(flag->width - n_symbol - 2, flag);
	s++;
	return (s);
}

char	*print_hex(char *s, va_list args, t_flag *flag)
{
	//inizia da qui
}