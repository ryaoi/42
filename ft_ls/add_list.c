/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 19:24:28 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/08 18:08:34 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_list(t_list **lst, char *str)
{
	t_list	*new;
	t_list	*ptr;
	DIR		*dir;

	ptr = *lst;
	new = (t_list *)malloc(sizeof(t_list));
	new->name = ft_strdup(str);
	new->next = NULL;
	if (ptr == NULL)
		*lst = new;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
	if (!(dir = opendir(str)))
		new->d = 0;
	else
	{
		new->d = 1;
		closedir(dir);
	}
}
