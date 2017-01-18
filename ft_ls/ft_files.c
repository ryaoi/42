/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:06:27 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/08 18:37:35 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_to_solo(t_list **ptr, t_file **solo, int *got_f,
					t_opt *opt)
{
	while ((*ptr) != NULL)
	{
		if ((*ptr)->d == 0 || opt->flag_d == 1)
		{
			(*got_f) = 1;
			if (check_permi((*ptr)->name) == 1 || opt->flag_d == 1)
			{
				add_filedata(solo, (*ptr)->name);
				(*ptr)->d = 5;
			}
		}
		(*ptr) = (*ptr)->next;
	}
}

int		newline(t_list *origin)
{
	if (count_list(origin) != count_list_d(origin))
		ft_printf("\n");
	else
		return (1);
	return (0);
}
