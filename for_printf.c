/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 20:08:40 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/03/24 20:08:41 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			specif(va_list f, char *sp, t_print *pr)
{
	if (*sp == 'n')
		specif_n(f, *pr);
	else if (*sp == 'c' || *sp == 'C')
		specif_c_lc(f, pr, sp);
	else if ((*sp == 's' && check_l_for_cs(sp)) || *sp == 'S')
		specif_ls(f, pr, 0);
	else if (*sp == 's')
		specif_s(f, pr);
	else if (*sp == 'p')
		specif_p(f, pr);
	else if (*sp == 'd' || *sp == 'i' || *sp == 'D')
		specif_di_ld(f, pr, *sp);
	else if (*sp == 'u' || *sp == 'o' || *sp == 'x' ||
			*sp == 'X' || *sp == 'b' || *sp == 'O' || *sp == 'U')
		specif_uoxb_luoxb(f, *sp, pr);
}

unsigned int	ft_atou(char **str)
{
	unsigned int	res;

	res = 0;
	while (ft_isdigit(**str))
	{
		res = (res * 10) + (**str - '0');
		(*str)++;
	}
	(*str)--;
	return (res);
}

int				precision(va_list f, char **tmp)
{
	int	res;

	res = -1;
	if (**tmp == '.')
	{
		if (ft_isdigit(*(*tmp + 1)))
		{
			(*tmp)++;
			res = ft_atou(tmp);
		}
		else if (*(*tmp + 1) == '*')
		{
			(*tmp)++;
			res = va_arg(f, int);
			(res < 0) ? res = -1 : 0;
		}
		else
			res = 0;
	}
	return (res);
}

void			length(char *tmp, char **size)
{
	if (*tmp == 'h' && **size != 'l' && **size != 'j' && **size != 'z')
		*size = (**size == 'h' && *(*size + 1) == '\0' ? "hh" : "h");
	else if (*tmp == 'l' && **size != 'j' && **size != 'z')
		*size = (**size == 'l' && *(*size + 1) == '\0' ? "ll" : "l");
	else if (*tmp == 'j' && **size != 'z')
		*size = "j";
	else if (*tmp == 'z' && **size != 'z')
		*size = "z";
}

void			flag(char tmp, t_print *pr)
{
	(tmp == '\'') ? pr->apostrophe = 1 : 0;
	(tmp == '-') ? pr->hyphen = 1 : 0;
	(tmp == '+') ? pr->plus = 1 : 0;
	(tmp == ' ') ? pr->space = 1 : 0;
	(tmp == '#') ? pr->hash = 1 : 0;
	(tmp == '0') ? pr->zero = 1 : 0;
}
