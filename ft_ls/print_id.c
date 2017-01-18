/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 20:33:53 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/18 17:23:27 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_id(t_file *head, t_file *origin)
{
	int		i;
	int		max;
	t_file	*ptr;

	ptr = origin;
	i = 0;
	max = 0;
	while (ptr != NULL)
	{
		i = count_str(ptr->usr_name);
		if (max < i)
			max = i;
		ptr = ptr->next;
	}
	ft_printf(" %s", head->usr_name);
	print_space(max, count_str(head->usr_name));
}

void		print_grp(t_file *head, t_file *origin)
{
	int		i;
	int		max;
	t_file	*ptr;

	ptr = origin;
	i = 0;
	max = 0;
	while (ptr != NULL)
	{
		i = count_str(ptr->grp_name);
		if (max < i)
			max = i;
		ptr = ptr->next;
	}
	ft_printf(" %s", head->grp_name);
	max = max - 1;
	print_space(max, count_str(head->grp_name));
}
