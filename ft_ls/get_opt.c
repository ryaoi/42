/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:36:23 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/09 13:44:39 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	take_it(t_opt **opt, char **argv, int i, int j)
{
	if (argv[i][j] == 'a')
		(*opt)->flag_a = 1;
	else if (argv[i][j] == 'l')
		(*opt)->flag_l = 1;
	else if (argv[i][j] == 'R')
		(*opt)->flag_capr = 1;
	else if (argv[i][j] == 'r')
		(*opt)->flag_r = 1;
	else if (argv[i][j] == 't')
		(*opt)->flag_t = 1;
	else if (argv[i][j] == 'g')
		(*opt)->flag_g = 1;
	else if (argv[i][j] == 'd')
		(*opt)->flag_d = 1;
	else if (argv[i][j] == 'm')
		(*opt)->flag_m = 1;
}

void		get_opt(t_opt **opt, int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		j = 1;
		if (ft_strcmp(argv[i], "--") == 0)
			return ;
		while (argv[i][j] != '\0')
		{
			take_it(opt, argv, i, j);
			j++;
		}
		i++;
	}
}
