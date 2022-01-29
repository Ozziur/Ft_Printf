/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:25:45 by mruizzo           #+#    #+#             */
/*   Updated: 2022/01/29 19:28:05 by mruizzo          ###   ########.fr       */
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
