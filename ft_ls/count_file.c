/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 19:00:38 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/17 19:01:27 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		count_file(t_file *head)
{
	int i;

	i = 0;
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}

int		count_list(t_list *head)
{
	int	i;

	i = 0;
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}

int		count_list_d(t_list *head)
{
	int	i;

	i = 0;
	while (head != NULL)
	{
		if (head->d == 5)
			i++;
		head = head->next;
	}
	return (i);
}
