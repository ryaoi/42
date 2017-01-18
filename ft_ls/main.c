/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:09:29 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/09 13:38:18 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				check_permi(char *str)
{
	struct stat		fs;

	if (lstat(str, &fs) < 0)
		exit(EXIT_FAILURE);
	if ((fs.st_mode & S_IXUSR) == 0 && (S_ISDIR(fs.st_mode)))
		return (0);
	return (1);
}

static	void	solo_file(t_opt *opt, t_list **lst)
{
	t_file			*solo;
	t_list			*ptr;
	int				got_f;

	ptr = *lst;
	solo = NULL;
	add_to_solo(&ptr, &solo, &got_f, opt);
	if (got_f == 1 && solo != NULL)
	{
		sort_file(&solo, opt);
		if (opt->flag_l == 1)
			printfiles(solo, opt);
		else
			ft_opt_no_l(solo, opt);
		freefile(&solo);
		if (newline(*lst))
			return ;
	}
}

static	void	dir_file(t_opt *opt, t_list **lst, int alert)
{
	t_list			*origin;
	t_list			*ptr;

	origin = *lst;
	ptr = *lst;
	while (ptr != NULL && opt->flag_d == 0)
	{
		check_denied(ptr->name, origin, &ptr);
		if (ptr->d == 1 && (check_permi(ptr->name) == 1))
		{
			if (opt->flag_capr == 0)
				ft_no_opt(ptr->name, opt, alert);
			else
			{
				if (count_list(origin) != 1 || alert == 1)
					ft_printf("%s:\n", ptr->name);
				ft_recursion(ptr->name, opt);
			}
			ptr->d = 5;
			if (newline(origin))
				return ;
		}
		ptr = ptr->next;
	}
}

int				main(int argc, char **argv)
{
	t_opt			*opt;
	int				alert;
	t_list			*lst;

	lst = NULL;
	no_argopt(argc);
	alert = 0;
	opt = init_opt();
	ft_opt_err(argv, opt);
	get_opt(&opt, argc, argv);
	check_dir(argv, &lst, &opt, &alert);
	no_arg(lst, alert, opt);
	sort_listname(&lst);
	solo_file(opt, &lst);
	dir_file(opt, &lst, alert);
	free(opt);
	freelist(&lst);
	return (0);
}
