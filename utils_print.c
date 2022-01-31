/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:25:45 by mruizzo           #+#    #+#             */
/*   Updated: 2022/01/31 17:40:03 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_base_str(char *s, size_t size, t_flag *flag)
{
	size_t	i;

	i = 0;
	while (s[i] && i < size)
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '%')
			{
				ft_putchar('%', flag);
				i++;
			}
		}
		else
			ft_putchar(s[i], flag);
		i++;
	}
	return (0);
}

void	printsymbol(int num, int n_symbol, t_flag *flag)
{
	if (num < 0 && (flag->zero && !flag->point))
		ft_putchar('-', flag);
	if (flag->width && !flag->minus)
		print_spaces(flag->width - n_symbol, flag);
	if (num < 0 && (!flag->zero && flag->point))
		ft_putchar('-', flag);
	if (flag->plus && num >= 0)
		ft_putchar('+', flag);
	if (flag->space && num >= 0 && !flag->plus)
		ft_putchar(' ', flag);
	if (flag->accuracy > len_num(num))
		print_zeroes(flag->accuracy - len_num(num), flag);
}

char	*print_integer(char *s, int num, t_flag *flag)
{
	int	n_symbol;

	n_symbol = len_num(num);
	if (((flag->plus || flag->space) && num >= 0) || num < 0)
		n_symbol++;
	if (num < 0 && flag->accuracy >= n_symbol)
		n_symbol = flag->accuracy + 1;
	if (flag->accuracy > n_symbol)
		n_symbol = flag->accuracy;
	if (flag->point && flag->accuracy == 0 && num == 0)
		n_symbol = 0;
	printsymbol(num, n_symbol, flag);
	ft_putnbr(num, flag);
	if (flag->width && flag->minus)
		print_spaces(flag->width - n_symbol, flag);
	return (++s);
}

char	*print_unsigned(char *s, va_list args, t_flag *flag)
{
	unsigned int	num;
	int				n_symbol;

	num = va_arg(args, unsigned int);
	n_symbol = len_num(num);
	if (flag->plus || flag->space)
		n_symbol++;
	if (flag->accuracy > n_symbol)
		n_symbol = flag->accuracy;
	if (flag->point && flag->accuracy == 0 && num == 0)
		n_symbol = 0;
	if (flag->width && !flag->minus)
		print_spaces(flag->width - n_symbol, flag);
	if (flag->plus)
		ft_putchar('+', flag);
	if (flag->space && !flag->plus)
		ft_putchar(' ', flag);
	if (flag->accuracy > len_num(num))
		print_zeroes(flag->accuracy - len_num(num), flag);
	ft_putnbr(num, flag);
	if (flag->width && flag->minus)
		print_spaces(flag->width - n_symbol, flag);
	s++;
	return (s);
}
