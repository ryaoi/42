/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subdesign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 09:26:43 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/09 09:37:31 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visu.h"

static void	sube_mlx(t_mw *mw)
{
	int		i;
	int		l;

	i = 130;
	while (i < 140)
	{
		l = 60;
		while (l < 120)
		{
			mlx_pixel_put(mw->mlx, mw->win, i, l, WHITE);
			l++;
		}
		i++;
	}
	i = 130;
	while (i < 170)
	{
		l = 110;
		while (l < 120)
		{
			mlx_pixel_put(mw->mlx, mw->win, i, l, WHITE);
			l++;
		}
		i++;
	}
}

static void	subsube_mlx(t_mw *mw)
{
	int		i;
	int		l;

	i = 160;
	while (i < 170)
	{
		l = 60;
		while (l < 80)
		{
			mlx_pixel_put(mw->mlx, mw->win, i, l, WHITE);
			l++;
		}
		i++;
	}
}

void		e_mlx(t_mw *mw, int i, int l)
{
	i = 130;
	while (i < 170)
	{
		l = 60;
		while (l < 70)
		{
			mlx_pixel_put(mw->mlx, mw->win, i, l, WHITE);
			l++;
		}
		i++;
	}
	i = 130;
	while (i < 170)
	{
		l = 80;
		while (l < 90)
		{
			mlx_pixel_put(mw->mlx, mw->win, i, l, WHITE);
			l++;
		}
		i++;
	}
	sube_mlx(mw);
	subsube_mlx(mw);
}
