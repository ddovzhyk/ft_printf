/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 20:15:12 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/03/24 20:15:13 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	check_modificator(char **str, va_list f, t_print *print)
{
	while (*(++*str) && (is_length(**str) || ft_isdigit(**str) ||
						is_flag(**str) || **str == '.' || **str == '*'))
		if (is_flag(**str))
			flag(**str, print);
		else if ((**str != '0' && ft_isdigit(**str)) || **str == '*')
		{
			print->width = (**str == '*') ? va_arg(f, int) : ft_atou(str);
			if (print->width < 0)
			{
				print->width *= (print->width == -2147483648) ? 0 : -1;
				print->hyphen = 1;
			}
		}
		else if (**str == '.')
		{
			(*str)++;
			print->prec = (**str == '*') ? va_arg(f, int) : ft_atou(str);
			if (print->prec < 0)
				print->prec = -1;
		}
		else if (is_length(**str))
			length(*str, &print->size);
}

void	check_spec_char(char **str, va_list f, t_print *print)
{
	char *tmp;

	if (is_specif(**str))
		specif(f, *str, print);
	else if (**str)
	{
		tmp = ft_strsub(*str, 0, 1);
		add_width_str(&tmp, *print, 1);
		print->byte += ft_strlen(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
	}
	else
		(*str)--;
}

int		is_specif(char c)
{
	return (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' ||
			c == 'X' || c == 'b' || c == 'c' || c == 's' || c == 'p' ||
			c == 'D' || c == 'O' || c == 'U' || c == 'C' || c == 'S' ||
			c == 'n' ? 1 : 0);
}

int		is_length(char c)
{
	return ((c == 'h' || c == 'l' || c == 'j' || c == 'z') ? 1 : 0);
}

int		is_flag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0' ||
			c == '\'' ? 1 : 0);
}
