/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 22:11:52 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/08 19:51:56 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		add_file(t_file **head, char *name, char *str)
{
	t_file	*new;
	t_file	*ptr;

	ptr = *head;
	if (!(new = (t_file *)malloc(sizeof(t_file))))
		exit(EXIT_FAILURE);
	new->name = ft_strdup(name);
	new->next = NULL;
	if (ptr == NULL)
		*head = new;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
	ft_inspect_file(&new, name, str);
}
