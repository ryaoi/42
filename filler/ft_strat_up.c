/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strat_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 20:32:35 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/11 19:51:58 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		failure(void)
{
	ft_printf("0 0\n");
	exit(0);
}

static int	invador(t_fil *fil, t_tetri tet)
{
	if (check_surroundx(tet.map, fil) == 1 &&
		check_line(tet.map, fil, 1, fil->line - 1) == 1)
	{
		if (virusdown(tet, fil) == 1)
			return (1);
	}
	if (check_line(tet.map, fil, 1, 0) == 1)
	{
		if (bottomright(tet, fil) == 1)
			return (1);
	}
	if (check_line(tet.map, fil, 1, fil->line / 4) == 0)
	{
		if (gotomiddlefromo(tet, fil) == 1)
			return (1);
	}
	return (0);
}

static int	invade(t_fil *fil, t_tetri tet)
{
	if (invador(fil, tet) == 1)
		return (1);
	else if (tet.map[0][fil->col - 1] == '.' && tet.tetri_x >= tet.tetri_y)
	{
		if (topright(tet, fil) == 0)
		{
			if (bottomright(tet, fil) == 0)
				failure();
		}
		return (1);
	}
	return (0);
}

void		strat_up(t_fil *fil, t_tetri tet)
{
	if (invade(fil, tet) == 1)
		return ;
	else if (tet.map[fil->line - 1][0] == '.')
	{
		if (bottomleft(tet, fil) == 0)
			failure();
	}
	else if (middletotopright(tet, fil) == 0)
	{
		if (bottomright(tet, fil) == 0)
		{
			if (bottomleft(tet, fil) == 0)
			{
				if (topleft(tet, fil) == 0)
					failure();
			}
		}
	}
}
