/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:13:04 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/09 14:15:50 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_opt_err(char **argv, t_opt *opt)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i] != NULL && argv[i][0] == '-')
	{
		j = 1;
		while ((argv[i][j] == 'r' || argv[i][j] == 'a' || argv[i][j] == 'R' ||
				argv[i][j] == 't' || argv[i][j] == 'l' || argv[i][j] == 'g' ||
				argv[i][j] == 'd' || argv[i][j] == 'm') && argv[i][j] != '\0')
			j++;
		if (argv[i][j] != '\0' && ft_strcmp(argv[i], "--") != 0)
		{
			ft_printf("ls: illegal option -- %c\n", argv[i][j]);
			ft_printf("usage: ls [-Radglmrt] [file ...]\n");
			free(opt);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
