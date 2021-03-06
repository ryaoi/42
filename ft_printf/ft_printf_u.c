/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:53:19 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/08 19:00:50 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_print_u_zero(t_pf **pf)
{
	int					i;

	i = 0;
	while (((*pf)->result)[i] != '\0')
	{
		if (((*pf)->result)[i] == '+')
			((*pf)->result)[0] = '+';
		else if (((*pf)->result)[i] == '-')
			((*pf)->result)[0] = '-';
		i++;
	}
	i = 0;
	if (((*pf)->result)[0] == '-' || ((*pf)->result)[0] == '+')
		i++;
	while (((*pf)->result)[i] != '\0')
	{
		if ((((*pf)->result)[i]) > '0' && (((*pf)->result)[i]) <= '9')
			break ;
		if (((*pf)->result)[i] == ' ' ||
			((*pf)->result)[i] == '-' || ((*pf)->result)[i] == '+')
			((*pf)->result)[i] = '0';
		i++;
	}
}

static void				ft_print_u_space(t_pf **pf)
{
	char				*tmp;
	size_t				size;
	int					i;

	i = 0;
	tmp = ft_strnew((*pf)->width);
	if ((*pf)->flag_zero == 1 && (*pf)->flag_minus == 0
		&& (*pf)->precision == 0)
		ft_memset(tmp, '0', (*pf)->width);
	else
		ft_memset(tmp, ' ', (*pf)->width);
	size = ft_strlen((*pf)->result);
	i = (*pf)->width;
	while (size > 0)
	{
		tmp[i - 1] = ((*pf)->result)[size - 1];
		i--;
		size--;
	}
	free((*pf)->result);
	(*pf)->result = ft_strdup(tmp);
	ft_strdel(&(tmp));
}

static void				ft_printf_u_precision(t_pf **pf,
						unsigned long long nbr)
{
	char				*str;
	int					i;
	int					j;

	i = 0;
	j = 0;
	str = ft_strnew((*pf)->precision);
	ft_memset(str, '0', (*pf)->precision);
	i = (*pf)->precision - ft_count_digit_base(nbr, 10);
	while (i != (*pf)->precision)
	{
		str[i] = ((*pf)->result)[j];
		i++;
		j++;
	}
	free((*pf)->result);
	(*pf)->result = ft_strdup(str);
	ft_strdel(&(str));
}

static	void			pre_digit(t_pf **pf, int *flag_p,
						unsigned long long nbr)
{
	ft_printf_u_precision(pf, nbr);
	(*flag_p) = 1;
}

void					ft_printf_u(t_pf **pf, va_list ap)
{
	unsigned long long	nbr;
	int					flag_p;

	flag_p = 0;
	nbr = va_arg(ap, unsigned long long);
	ft_length_ull(pf, nbr, 10);
	if ((*pf)->precision > ft_ucount_digit_base(nbr, 10))
		pre_digit(pf, &flag_p, nbr);
	if (((*pf)->width > (*pf)->precision && (*pf)->width
		> ft_ucount_digit_base(nbr, 10)))
		ft_print_u_space(pf);
	if (((*pf)->width > (*pf)->precision || (*pf)->width
		> ft_ucount_digit_base(nbr, 10)) && ((*pf)->flag_zero)
		&& flag_p != 1 && (*pf)->flag_minus == 0)
		ft_print_u_zero(pf);
	ft_check_dec(pf);
	if ((*pf)->flag_minus == 1)
		ft_stradjust(pf);
	ft_putstr((*pf)->result);
	(*pf)->ret = ft_strlen((*pf)->result);
	free((*pf)->result);
}
