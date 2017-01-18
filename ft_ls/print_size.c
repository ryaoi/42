/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 20:53:57 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/08 16:23:33 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				check_bc(t_file *origin)
{
	while (origin != NULL)
	{
		if (origin->mode[0] == 'b' || origin->mode[0] == 'c')
			return (1);
		origin = origin->next;
	}
	return (0);
}

void			print_maj(t_file *head, t_file *origin)
{
	int		i;
	int		max;
	t_file	*ptr;

	ptr = origin;
	i = 0;
	max = 0;
	while (ptr != NULL)
	{
		i = count_digit(ptr->maj);
		if (max < i)
			max = i;
		ptr = ptr->next;
	}
	ft_printf(" ");
	if (head->mode[0] == 'c' || head->mode[0] == 'b')
	{
		print_space_num(max, count_digit(head->maj));
		ft_printf("%zu,", head->maj);
	}
	else
		print_space_num(max + 1, 0);
}

static void		search_max(int *i, int *max, t_file *ptr)
{
	*i = 0;
	*max = 0;
	while (ptr != NULL)
	{
		*i = count_digit(ptr->size);
		if (*max < *i)
			*max = *i;
		ptr = ptr->next;
	}
}

void			print_size(t_file *head, t_file *origin)
{
	int		i;
	int		max;
	t_file	*ptr;

	ptr = origin;
	search_max(&i, &max, ptr);
	if (max < 3)
		ft_printf("%4zu", head->size);
	else if (check_bc(origin))
	{
		print_space_num(max - 2, count_digit(head->size));
		ft_printf("%zu", head->size);
	}
	else
	{
		print_space_num(max, count_digit(head->size));
		ft_printf("%zu", head->size);
	}
}
