/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_design.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 09:01:33 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/09 09:41:31 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visu.h"

static void	l_mlx(t_mw *mw)
{
	int		i;
	int		l;

	i = 90;
	while (i < 100)
	{
		l = 20;
		while (l < 120)
		{
			mlx_pixel_put(mw->mlx, mw->win, i, l, WHITE);
			l++;
		}
		i++;
	}
}

static void	secondl_mlx(t_mw *mw)
{
	int		i;
	int		l;

	i = 110;
	while (i < 120)
	{
		l = 20;
		while (l < 120)
		{
			mlx_pixel_put(mw->mlx, mw->win, i, l, WHITE);
			l++;
		}
		i++;
	}
}

static void	i_mlx(t_mw *mw)
{
	int		i;
	int		l;

	i = 70;
	while (i < 80)
	{
		l = 60;
		while (l < 70)
		{
			mlx_pixel_put(mw->mlx, mw->win, i, l, WHITE);
			l++;
		}
		i++;
	}
	i = 70;
	while (i < 80)
	{
		l = 80;
		while (l < 120)
		{
			mlx_pixel_put(mw->mlx, mw->win, i, l, WHITE);
			l++;
		}
		i++;
	}
}

static void	f_mlx(t_mw *mw)
{
	int		i;
	int		l;

	i = 20;
	while (i < 30)
	{
		l = 30;
		while (l < 120)
		{
			mlx_pixel_put(mw->mlx, mw->win, i, l, WHITE);
			l++;
		}
		i++;
	}
	i = 20;
	while (i < 60)
	{
		l = 60;
		while (l < 70)
		{
			mlx_pixel_put(mw->mlx, mw->win, i, l, WHITE);
			l++;
		}
		i++;
	}
}

void		header_filler(t_mw *mw)
{
	int		i;
	int		l;

	i = 20;
	while (i < 80)
	{
		l = 20;
		while (l < 30)
		{
			mlx_pixel_put(mw->mlx, mw->win, i, l, WHITE);
			l++;
		}
		i++;
	}
	f_mlx(mw);
	i_mlx(mw);
	l_mlx(mw);
	secondl_mlx(mw);
	e_mlx(mw, 0, 0);
	r_mlx(mw);
}
