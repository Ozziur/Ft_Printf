/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:29:33 by mruizzo           #+#    #+#             */
/*   Updated: 2022/02/20 18:38:47 by mruizzo          ###   ########.fr       */
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

void	print_zeroes(int n, t_flag *flag)
{
	while (n > 0)
	{
		ft_putchar('0', flag);
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

char	*print_str(char *s, char *arg, t_flag *flag)
{
	int	len;

	len = ft_strlen_pf(arg);
	if (arg == NULL)
		len = 6;
	if (flag->point && flag->accuracy < len)
		len = flag->accuracy;
	if (flag ->width && !flag->minus)
		print_spaces(flag->width - len, flag);
	if (arg != NULL)
		ft_putstr(arg, flag);
	else
		ft_putstr("(null)", flag);
	if (flag ->width && flag->minus)
		print_spaces(flag->width - len, flag);
	s++;
	return (s);
}

int	ft_putnbr(long long n, t_flag *flag)
{
	char	result[18];
	int		i;

	if (flag->point && flag->accuracy == 0 && n == 0)
		return (0);
	i = 1;
	if (n == 0)
		ft_putchar('0', flag);
	if (n < 0)
	{
		n = -n;
		if (!flag->zero && !flag->point)
			ft_putchar('-', flag);
	}
	while (n)
	{
		result[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	i--;
	while (i)
		ft_putchar(result[i--], flag);
	return (0);
}
