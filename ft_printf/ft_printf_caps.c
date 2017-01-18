/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_caps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:03:02 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/12 14:10:33 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_null(t_pf **pf, wchar_t *str)
{
	if (str == NULL)
	{
		(*pf)->ret = 6;
		ft_putstr("(null)");
		return (1);
	}
	return (0);
}

static void		pre_dot(t_pf **pf, wchar_t *str)
{
	if ((*pf)->precision != 0)
	{
		(*pf)->ret = (*pf)->precision;
		ft_printf_str_unicode(str, (*pf)->precision);
	}
	else
		(*pf)->ret = (*pf)->width;
}

static void		no_flag(t_pf **pf, wchar_t *str)
{
	(*pf)->ret = ft_wstrlen(str);
	ft_printf_str_unicode(str, (*pf)->ret);
}

static void		zero_or_space(t_pf **pf, wchar_t *str)
{
	(*pf)->result = ft_strnew((*pf)->width - ft_wstrlen(str));
	if ((*pf)->flag_zero == 0)
		ft_memset((*pf)->result, ' ', (*pf)->width - ft_wstrlen(str));
	else
		ft_memset((*pf)->result, '0', (*pf)->width - ft_wstrlen(str));
}

void			ft_printf_caps(t_pf **pf, va_list ap)
{
	wchar_t		*str;

	str = va_arg(ap, wchar_t *);
	if (print_null(pf, str))
		return ;
	if ((*pf)->width > ft_wstrlen(str))
	{
		(*pf)->ret = (*pf)->width;
		zero_or_space(pf, str);
		if ((*pf)->flag_minus == 1)
		{
			ft_printf_str_unicode(str, ft_wstrlen(str));
			ft_putstr((*pf)->result);
			return ;
		}
		else
		{
			ft_putstr((*pf)->result);
			ft_printf_str_unicode(str, ft_wstrlen(str));
		}
	}
	if ((*pf)->precision != 0 || (*pf)->flag_dot != 0)
		pre_dot(pf, str);
	else
		no_flag(pf, str);
}
