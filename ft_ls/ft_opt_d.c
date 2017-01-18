/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:13:01 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/08 16:14:42 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_opt_d(t_opt **opt)
{
	t_file	*solo;

	solo = NULL;
	add_filedata(&solo, ".");
	(*opt)->flag_a = 1;
	if ((*opt)->flag_l == 1)
		printfiles(solo, *opt);
	else
		ft_opt_no_l(solo, *opt);
	freeonefile(&solo);
}
