/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:11:41 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/18 17:26:52 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_opt		*init_opt(void)
{
	t_opt	*new;

	new = (t_opt *)malloc(sizeof(t_opt));
	new->flag_r = 0;
	new->flag_a = 0;
	new->flag_capr = 0;
	new->flag_l = 0;
	new->flag_t = 0;
	new->flag_g = 0;
	new->flag_d = 0;
	new->flag_m = 0;
	new->solo = 0;
	return (new);
}
