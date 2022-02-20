/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:19:38 by mruizzo           #+#    #+#             */
/*   Updated: 2022/02/20 18:39:01 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_pf(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_pf(const char *s, int c)
{
	unsigned char	ch;

	ch = (unsigned char) c;
	while ((*s != '\0') && (*s != ch))
	{
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return ((char *) NULL);
}

void	ft_putchar(char ch, t_flag *flag)
{
	write(1, &ch, 1);
	flag->counter++;
}

void	ft_putstr(char *str, t_flag *flag)
{
	int	len;

	if (str)
	{
		len = ft_strlen_pf(str);
		if (flag->point && flag->accuracy < len && flag->type == 's')
			len = flag->accuracy;
		write(1, str, len);
		flag->counter += len;
	}
}
