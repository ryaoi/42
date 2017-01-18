/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 18:58:48 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/08 18:11:59 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		sort_listname(t_list **lst)
{
	t_list	*ptr;
	t_list	*ptr2;

	ptr = *lst;
	while (ptr->next != NULL)
	{
		ptr2 = ptr->next;
		while (ptr2 != NULL)
		{
			if (ft_strcmp(ptr->name, ptr2->name) > 0)
				swap_list(ptr, ptr2);
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
}

void		sort_name(t_file **file)
{
	t_file	*ptr;
	t_file	*ptr2;

	ptr = *file;
	if (count_file(ptr) == 2)
	{
		if (ft_strcmp(ptr->name, ptr->next->name) > 0)
			swap_file(ptr, ptr->next);
	}
	while (ptr->next != NULL)
	{
		ptr2 = ptr->next;
		while (ptr2 != NULL)
		{
			if (ft_strcmp(ptr->name, ptr2->name) > 0)
				swap_file(ptr, ptr2);
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
}

static int	ft_timecmp(int time1, int time2)
{
	return (time1 - time2);
}

void		sort_time(t_file **file)
{
	t_file	*ptr;
	t_file	*ptr2;

	ptr = *file;
	if (count_file(ptr) == 2)
	{
		if (ft_timecmp(ptr->md_time, ptr->next->md_time) < 0)
			swap_file(ptr, ptr->next);
	}
	while (ptr->next != NULL)
	{
		ptr2 = ptr->next;
		while (ptr2 != NULL)
		{
			if (ft_timecmp(ptr->md_time, ptr2->md_time) < 0)
				swap_file(ptr, ptr2);
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
}
