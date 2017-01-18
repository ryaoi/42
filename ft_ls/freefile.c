/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:35:05 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/09 13:40:22 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	freefile(t_file **head)
{
	t_file	*ptr;
	t_file	*ptr_next;

	ptr = *head;
	while (ptr != NULL)
	{
		free((ptr)->name);
		ptr->attri = 0;
		free((ptr)->mode);
		free((ptr)->linked);
		free((ptr)->usr_name);
		free((ptr)->grp_name);
		free((ptr)->mod_time);
		ptr_next = ptr->next;
		free((ptr));
		ptr = ptr_next;
	}
}

void	freeonefile(t_file **head)
{
	t_file	*ptr;

	ptr = *head;
	ptr->attri = 0;
	free((ptr)->name);
	free((ptr)->mode);
	free((ptr)->linked);
	free((ptr)->usr_name);
	free((ptr)->grp_name);
	free((ptr)->mod_time);
	free((ptr));
}

void	freelist(t_list **head)
{
	t_list	*ptr;
	t_list	*ptr_next;

	ptr = *head;
	while (ptr != NULL)
	{
		free((ptr)->name);
		ptr_next = ptr->next;
		free((ptr));
		ptr = ptr_next;
	}
}
