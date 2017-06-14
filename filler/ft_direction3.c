/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:53:14 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/11 19:44:42 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				gotomiddlefromx(t_tetri tet, t_fil *fil)
{
	int		i;
	int		l;

	i = (fil->line - 1) * 3 / 4;
	while (i >= 0)
	{
		l = fil->col - 1;
		while (l >= 0)
		{
			if (valid_put(tet, i, l, fil) == 1)
				return (1);
			l--;
		}
		i--;
	}
	return (0);
}

int				risingtopleft(t_tetri tet, t_fil *fil)
{
	int		i;
	int		l;
	int		check;

	i = (fil->line - 1);
	while (i >= 0)
	{
		l = 0;
		check = 0;
		while (l < fil->col - 1)
		{
			if (tet.map[i][l] == fil->c)
				check = 1;
			if (tet.map[i][l] != fil->c && check == 1)
				l = fil->col - 2;
			else if (valid_put(tet, i, l, fil) == 1)
				return (1);
			l++;
		}
		i--;
	}
	return (0);
}

int				curvingtopleft(t_tetri tet, t_fil *fil)
{
	int		i;
	int		l;
	int		check;

	i = 0;
	while (i < fil->col - 1)
	{
		l = 0;
		check = 0;
		while (l < fil->line - 1)
		{
			if (tet.map[l][i] == fil->c)
				check = 1;
			if (tet.map[l][i] != fil->c && check == 1)
				l = fil->line - 2;
			else if (valid_put(tet, l, i, fil) == 1)
				return (1);
			l++;
		}
		i++;
	}
	return (0);
}

int				bottomwall(t_tetri tet, t_fil *fil)
{
	int		i;
	int		l;
	int		check;

	i = fil->line * 3 / 4;
	while (i < fil->line * 5 / 6)
	{
		l = 0;
		check = 0;
		while (l < fil->col - 1)
		{
			if (valid_put(tet, i, l, fil) == 1)
				return (1);
			l++;
		}
		i++;
	}
	return (0);
}
