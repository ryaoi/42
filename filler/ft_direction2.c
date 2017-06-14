/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 04:14:18 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/08 04:14:19 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			fromoriginy(t_tetri tet, t_fil *fil)
{
	int		l;

	l = 0;
	while (l < fil->col)
	{
		if (valid_put(tet, fil->my_y, l, fil) == 1)
			return (1);
		l++;
	}
	return (0);
}

int			fromoriginx(t_tetri tet, t_fil *fil)
{
	int		l;

	l = 0;
	while (l < fil->line)
	{
		if (valid_put(tet, l, fil->my_x, fil) == 1)
			return (1);
		l++;
	}
	return (0);
}

int			fromoriginxdown(t_tetri tet, t_fil *fil)
{
	int		l;

	l = fil->line - 1;
	while (l >= 0)
	{
		if (valid_put(tet, l, fil->my_x, fil) == 1)
			return (1);
		l--;
	}
	return (0);
}

int			fromoriginydown(t_tetri tet, t_fil *fil)
{
	int		l;

	l = fil->col - 1;
	while (l >= 0)
	{
		if (valid_put(tet, fil->my_y, l, fil) == 1)
			return (1);
		l--;
	}
	return (0);
}

int			bottomleft(t_tetri tet, t_fil *fil)
{
	int		i;
	int		l;

	i = fil->line - 1;
	while (i >= 0)
	{
		l = 0;
		while (l < fil->col)
		{
			if (valid_put(tet, i, l, fil) == 1)
				return (1);
			l++;
		}
		i--;
	}
	return (0);
}
