/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:15:50 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/18 02:01:06 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_space(int max, int value)
{
	char	*tmp;

	tmp = ft_strnew(max - value + 1);
	ft_memset(tmp, ' ', max - value + 1);
	ft_printf("%s", tmp);
	free(tmp);
}

void	print_space_num(int max, int value)
{
	char	*tmp;

	tmp = ft_strnew(2 + max - value);
	ft_memset(tmp, ' ', 2 + max - value);
	ft_printf("%s", tmp);
	free(tmp);
}

void	print_space_link(int max, int value, int at)
{
	char	*tmp;

	if (at)
	{
		tmp = ft_strnew(1 + max - value);
		ft_memset(tmp, ' ', 1 + max - value);
	}
	else
	{
		tmp = ft_strnew(2 + max - value);
		ft_memset(tmp, ' ', 2 + max - value);
	}
	ft_printf("%s", tmp);
	free(tmp);
}
