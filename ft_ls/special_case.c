/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:15:15 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/08 19:09:08 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	no_argopt(int argc)
{
	if (argc == 1)
	{
		no_optarg();
		exit(EXIT_SUCCESS);
	}
}

void	no_arg(t_list *lst, int alert, t_opt *opt)
{
	if (lst == NULL && alert != 1)
	{
		if (opt->flag_d == 1)
			ft_opt_d(&opt);
		else if (opt->flag_capr == 0)
			ft_no_opt(".", opt, alert);
		else
			ft_recursion(".", opt);
		free(opt);
		exit(EXIT_SUCCESS);
	}
}
