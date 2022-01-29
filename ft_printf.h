/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:34:48 by mruizzo           #+#    #+#             */
/*   Updated: 2022/01/29 19:30:25 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flag
{
	char	type;
	int		counter;
	int		minus;
	int		zero;
	int		point;
	int		accuracy;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		uppercase;
}	t_flag;

int		ft_printf(const char *str, ...);
void	reset_flag(t_flag *flag);
t_flag	*create_flag(void);
char	*get_flags(char *s, t_flag *flag, va_list args);
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
int		ft_atoi(const char *str);
void	analize_flags(char *s, t_flag *flag);
char	*next_arg(char *s);
char	*scan_arg(char *s, va_list args, t_flag *flag);
char	*print_char(char *s, va_list args, t_flag *flag);
void	ft_putchar(char ch, t_flag *flag);
int		print_base_str(char *s, size_t size, t_flag *flag);
char	*scan_args(char *s, va_list args, t_flag *flag);

#endif
