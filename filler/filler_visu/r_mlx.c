/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_mlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 09:39:18 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/09 09:44:00 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visu.h"

void		r_mlx(t_mw *mw)
{
	int		i;
	int		l;

	i = 180;
	while (i < 190)
	{
		l = 60;
		while (l < 120)
		{
			mlx_pixel_put(mw->mlx, mw->win, i, l, WHITE);
			l++;
		}
		i++;
	}
	i = 180;
	while (i < 210)
	{
		l = 65;
		while (l < 75)
		{
			mlx_pixel_put(mw->mlx, mw->win, i, l, WHITE);
			l++;
		}
		i++;
	}
}
