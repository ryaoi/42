/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:17:22 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/09 14:15:25 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		check_file(char *argv)
{
	struct stat		buff;
	int				ret;

	ret = 0;
	if (stat(argv, &buff) == 0)
		ret = 1;
	return (ret);
}

static int		check_err(char *argv, int *alert)
{
	DIR			*dir;

	if ((!(check_file(argv))))
	{
		if (!(dir = opendir(argv)))
		{
			*alert = 1;
			ft_printf("ft_ls: %s: No such file or directory\n", argv);
		}
		else
			closedir(dir);
		return (1);
	}
	return (0);
}

static void		ended(t_list **lst, int *alert, t_opt **opt)
{
	if (count_list(*lst) == 0 && *alert == 1)
	{
		free(*opt);
		exit(EXIT_SUCCESS);
	}
}

void			check_dir(char **argv, t_list **lst, t_opt **opt, int *alert)
{
	if (*argv == NULL)
		return ;
	if (ft_strcmp(*argv, "./ft_ls") == 0)
		argv++;
	while (*argv != NULL && (*argv)[0] == '-' && (*argv)[1] != '\0')
	{
		if (ft_strcmp(*argv, "--") == 0)
		{
			argv++;
			break ;
		}
		argv++;
	}
	while (*argv != NULL)
	{
		if (check_err(*argv, alert) == 0)
		{
			(*opt)->solo += 1;
			add_list(lst, *argv);
		}
		argv++;
	}
	ended(lst, alert, opt);
}
