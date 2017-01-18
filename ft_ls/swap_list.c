/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:22:35 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/08 16:22:38 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swap_list(t_list *ptr, t_list *ptr2)
{
	char	*tmp;
	int		d_tmp;

	tmp = ft_strdup(ptr->name);
	free(ptr->name);
	ptr->name = ft_strdup(ptr2->name);
	free(ptr2->name);
	ptr2->name = ft_strdup(tmp);
	free(tmp);
	d_tmp = ptr->d;
	ptr->d = ptr2->d;
	ptr2->d = d_tmp;
}
