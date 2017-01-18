/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 18:56:26 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/08 18:37:13 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	void		print_mod(t_file *head, t_file *origin, int at)
{
	int				i;
	int				max;
	t_file			*ptr;

	ptr = origin;
	i = 0;
	max = 0;
	ft_printf("%s", head->mode);
	if (at)
		ft_printf("%c", head->attri);
	while (ptr != NULL)
	{
		i = count_digit(ptr->link);
		max = (max < i ? i : max);
		ptr = ptr->next;
	}
	if (max < 2 && at == 0)
		ft_printf("  %d", head->link);
	else if (max < 2 && at == 1)
		ft_printf(" %d", head->link);
	else
	{
		print_space_link(max, count_digit(head->link), at);
		ft_printf("%d", head->link);
	}
}

static void			print_total(t_file *head)
{
	int				total;
	t_file			*ptr;

	total = 0;
	ptr = head;
	while (ptr != NULL)
	{
		total += ptr->block;
		ptr = ptr->next;
	}
	ft_printf("total %d\n", total);
}

void				print_all(t_file *head, t_file *origin, int at,
					t_opt *opt)
{
	print_mod(head, origin, at);
	if (opt->flag_g == 0)
		print_id(head, origin);
	print_grp(head, origin);
	if (check_bc(origin))
		print_maj(head, origin);
	print_size(head, origin);
	ft_printf(" %s %s", head->mod_time, head->name);
	if (head->mode[0] == 'l')
		ft_printf(" -> %s", head->linked);
	ft_printf("\n");
}

void				ft_opt_l(t_file *head, t_opt *opt)
{
	t_file			*origin;
	int				at;

	origin = head;
	print_total(head);
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

void				ft_opt_no_l(t_file *head, t_opt *opt)
{
	while (head != NULL)
	{
		if (opt->flag_a == 0)
		{
			if ((ft_strcmp(head->name, ".") != 0
				&& ft_strcmp(head->name, "..") != 0
				&& (head->name)[0] != '.') || opt->flag_d == 1)
			{
				if (opt->flag_m == 1 && head->next != NULL)
					ft_printf("%s, ", head->name);
				else
					ft_printf("%s\n", head->name);
			}
		}
		else
		{
			if (opt->flag_m == 1 && head->next != NULL)
				ft_printf("%s, ", head->name);
			else
				ft_printf("%s\n", head->name);
		}
		head = head->next;
	}
}
