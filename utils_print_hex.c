/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:57:52 by mruizzo           #+#    #+#             */
/*   Updated: 2022/02/02 16:28:16 by mruizzo          ###   ########.fr       */
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

void	ft_putnbr_hex(char ch, long long num, t_flag *flag)
{
	char	result[18];
	int		i;
	char	*base;

	if (flag->point && flag->accuracy == 0 && num == 0)
		return ;
	i = 1;
	if (num == 0)
		ft_putchar('0', flag);
	if (ch == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	while (num)
	{
		result[i] = base[num % 16];
		num = num / 16;
		i++;
	}
	i--;
	while (i)
	{
		ft_putchar(result[i], flag);
		i--;
	}
}

void	print_hex_flag(char *s, long long num, int n_symbol, t_flag *flag)
{
	if (num < 0 && (flag->zero || flag->point))
		ft_putchar('-', flag);
	if (flag->width && !flag->minus)
		print_spaces(flag->width - n_symbol, flag);
	if (flag->plus && num >= 0)
		ft_putchar('+', flag);
	if (flag->space && num >= 0 && !flag->plus)
		ft_putchar(' ', flag);
	if (flag->accuracy > len_num_hex(num))
		print_zeroes(flag->accuracy - len_num_hex(num), flag);
	if (flag->hash && num != 0)
	{
		if (*s == 'x')
			ft_putstr("0x", flag);
		else
			ft_putstr("0X", flag);
	}	
}

char	*print_hex(char *s, va_list args, t_flag *flag)
{
	long long	num;
	int			n_symbol;

	num = (long long)va_arg(args, unsigned int);
	n_symbol = len_num_hex(num);
	if (((flag->plus || flag->space) && num >= 0) || num < 0)
		n_symbol++;
	if (flag->accuracy > n_symbol)
		n_symbol = flag->accuracy;
	if (num < 0 && flag->accuracy >= n_symbol)
		n_symbol = flag->accuracy + 1;
	if (flag->point && flag->accuracy == 0 && num == 0)
		n_symbol = 0;
	print_hex_flag(s, num, n_symbol, flag);
	ft_putnbr_hex(*s, num, flag);
	if (flag->width && flag->minus)
		print_spaces(flag->width - n_symbol, flag);
	return (++s);
}
