/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:24:27 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/08 18:17:45 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				options(t_file **head, t_opt *opt)
{
	sort_name(head);
	if (opt->flag_t == 1)
		sort_time(head);
	if (opt->flag_r == 1)
		sort_reverse(head);
	if (opt->flag_l != 0)
		ft_opt_l(*head, opt);
	else
		ft_opt_no_l(*head, opt);
}

void				ft_no_opt(char *str, t_opt *opt, int alert)
{
	DIR				*dir;
	struct dirent	*dent;
	t_file			*head;

	head = NULL;
	if ((dir = opendir(str)) != NULL)
	{
		if (opt->solo > 1 || alert != 0)
			ft_printf("%s:\n", str);
		while ((dent = readdir(dir)) != NULL)
		{
			if (opt->flag_a == 1)
				add_file(&head, dent->d_name, str);
			else if (ft_strcmp(dent->d_name, ".") != 0
					&& ft_strcmp(dent->d_name, "..") != 0
					&& (dent->d_name)[0] != '.')
				add_file(&head, dent->d_name, str);
		}
		if (head == NULL)
			return ;
		options(&head, opt);
		freefile(&head);
		closedir(dir);
	}
}

void				no_optarg(void)
{
	DIR				*dir;
	struct dirent	*dent;
	t_file			*head;
	t_file			*origin;

	head = NULL;
	if ((dir = opendir(".")) != NULL)
	{
		while ((dent = readdir(dir)) != NULL)
			add_file(&head, dent->d_name, ".");
		sort_name(&head);
		origin = head;
		while (head != NULL)
		{
			if (ft_strcmp(head->name, ".") != 0
				&& ft_strcmp(head->name, "..") != 0
				&& (head->name)[0] != '.')
				ft_printf("%s\n", head->name);
			head = head->next;
		}
		freefile(&origin);
		closedir(dir);
	}
}
