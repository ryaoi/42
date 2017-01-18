/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:26:20 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/09 13:59:46 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char			*check_file(t_file *head, char *str)
{
	char			*stock;
	char			*next;

	next = NULL;
	if (head->mode[0] == 'd' && ft_strcmp(head->name, ".") != 0
		&& ft_strcmp(head->name, "..") != 0)
	{
		stock = ft_strjoin(str, "/");
		next = ft_strjoin(stock, head->name);
		free(stock);
		if ((head->mode[3] & S_IXUSR) == 0)
		{
			ft_printf("\n%s:\n", next);
			ft_printf("ft_ls: %s: Permission denied\n", head->name);
			free(next);
			next = NULL;
		}
	}
	return (next);
}

static t_file		*insert_head(char *str, t_opt *opt, DIR *dir)
{
	t_file			*new;
	struct dirent	*dent;

	new = 0;
	while ((dent = readdir(dir)) != NULL)
	{
		if (opt->flag_a == 1)
			add_file(&new, dent->d_name, str);
		else if (ft_strcmp(dent->d_name, ".") != 0
				&& ft_strcmp(dent->d_name, "..") != 0
				&& (dent->d_name)[0] != '.')
			add_file(&new, dent->d_name, str);
	}
	return (new);
}

static void			free_and_move(t_file **head)
{
	t_file			*frefile;

	frefile = (*head);
	(*head) = (*head)->next;
	freeonefile(&frefile);
}

void				ft_recursion(char *str, t_opt *opt)
{
	DIR				*dir;
	char			*next;
	t_file			*head;
	t_file			*origin;

	head = NULL;
	next = NULL;
	if ((dir = opendir(str)) != NULL)
	{
		head = insert_head(str, opt, dir);
		if (head != NULL)
			options(&head, opt);
		closedir(dir);
		origin = head;
		while (head != NULL)
		{
			if ((next = check_file(head, str)) != NULL)
			{
				ft_printf("\n%s:\n", next);
				ft_recursion(next, opt);
				free(next);
			}
			free_and_move(&head);
		}
	}
}
