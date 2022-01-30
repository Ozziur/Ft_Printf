/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:05:42 by mruizzo           #+#    #+#             */
/*   Updated: 2022/01/30 17:28:29 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	analize_flags(char *s, t_flag *flag)
{
	if (*s == '-')
		flag->minus = 1;
	if (*s == '.')
		flag->point = 1;
	if (*s == '#')
		flag->hash = 1;
	if (*s == ' ')
		flag->space = 1;
	if (*s == '+')
		flag->plus = 1;
	if (*s == '0')
		flag->zero = 1;
}

char	*get_flags(char *s, t_flag *flag/*, va_list args*/)
{
	while (!ft_strchr("cspdiuxX%", *s))
	{
		analize_flags(s, flag);
		if (ft_isdigit(*s) && flag->point)
			flag->accuracy = ft_atoi(s);
		else if (ft_isdigit(*s))
			flag->width = ft_atoi(s);
		while (ft_isdigit(*s) && ft_isdigit(*(s + 1)))
			s++;
		s++;
	}
	if (flag->minus || flag->point)
		flag->zero = 0;
	flag->type = *s;
	return (s);
}

char	*next_arg(char *s)
{
	while (*s)
	{
		if (*s == '%' && *(s + 1) != '%')
		{
			s++;
			return (s);
		}
		if (*s == '%')
			s++;
		s++;
	}
	return (s);
}

char	*scan_arg(char *s, va_list args, t_flag *flag)
{
	if (*s == 'c')
		return (print_char(s, args, flag));
	else if (*s == 's')
		return (print_str(s, va_arg(args, char *), flag));
	return (s);
	/*ricomincia da qui*/
}
