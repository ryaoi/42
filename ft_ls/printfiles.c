/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 22:33:03 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/08 18:38:01 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			sort_file(t_file **head, t_opt *opt)
{
	sort_name(head);
	if (opt->flag_t == 1)
		sort_time(head);
	if (opt->flag_r == 1)
		sort_reverse(head);
}

void			printfiles(t_file *head, t_opt *opt)
{
	t_file		*origin;
	int			at;
	int			i;

	i = 0;
	origin = head;
	at = check_attr(head, opt);
	while (head != NULL)
	{
		if (opt->flag_a == 0)
		{
			if ((ft_strcmp(head->name, ".") != 0
				&& ft_strcmp(head->name, "..") != 0
				&& (head->name)[0] != '.') || opt->flag_d == 1)
				print_all(head, origin, at, opt);
		}
		else
			print_all(head, origin, at, opt);
		head = head->next;
	}
}
