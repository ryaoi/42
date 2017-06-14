/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strat_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 13:08:34 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/11 19:56:55 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	wall_leftside(t_fil *fil, t_tetri tet)
{
	if (check_side(tet.map, fil, 1, fil->col - 1) == 0
		&& check_side(tet.map, fil, 1, 0) == 0)
	{
		if (bottomwall(tet, fil) == 0)
		{
			if (curvingtopleft(tet, fil) == 0)
			{
				if (bottomright(tet, fil) == 0)
					failure();
			}
		}
		return (1);
	}
	else if (check_side(tet.map, fil, 2, fil->col - 1) == 0
		&& tet.tetri_x >= tet.tetri_y)
	{
		if (topright(tet, fil) == 0)
		{
			if (risingtopleft(tet, fil) == 0)
				failure();
		}
		return (1);
	}
	else
		return (0);
}

static int	wall_rightside(t_fil *fil, t_tetri tet)
{
	if (tet.map[fil->line - 1][fil->col - 1] == '.'
		&& check_line(tet.map, fil, 1, fil->line - 1) == 0)
	{
		if (bottomright(tet, fil) == 0)
		{
			if (topright(tet, fil) == 0)
				failure();
		}
		return (1);
	}
	else
		return (0);
}

void		strat_down(t_fil *fil, t_tetri tet)
{
	if (wall_leftside(fil, tet) == 1)
		return ;
	if (wall_rightside(fil, tet) == 1)
		return ;
	else if (tet.map[0][0] == '.'
			&& check_line(tet.map, fil, 0, fil->line - 1) == 0)
	{
		if (curvingtopleft(tet, fil) == 0)
		{
			if (topleft(tet, fil) == 0)
				failure();
		}
	}
	else
	{
		if (topright(tet, fil) == 0)
		{
			if (virusdown(tet, fil) == 0)
			{
				if (topleft(tet, fil) == 0)
					failure();
			}
		}
	}
}
