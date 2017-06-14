/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:39:25 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/11 19:40:13 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			check_line(char **tab, t_fil *fil, int l, int line)
{
	int		i;

	i = 0;
	while (tab[line][i] != '\0')
	{
		if (l == 0 && tab[line][i] == fil->enemy_c)
			return (1);
		if (l == 1 && tab[line][i] == fil->c)
			return (1);
		if (l == 2)
		{
			if (tab[line][i] == fil->c || tab[line][i] == fil->enemy_c)
				return (1);
		}
		i++;
	}
	return (0);
}

int			check_side(char **tab, t_fil *fil, int l, int side)
{
	int		i;
	int		lim;

	if (side == 0)
		lim = 0;
	else
		lim = fil->col - 1;
	i = 0;
	while (i < fil->line - 1)
	{
		if (l == 0 && tab[i][lim] == fil->enemy_c)
			return (1);
		if (l == 1 && tab[i][lim] == fil->c)
			return (1);
		if (l == 2)
		{
			if (tab[i][lim] == fil->c || tab[i][lim] == fil->enemy_c)
				return (1);
		}
		i++;
	}
	return (0);
}

static void	puttetri(char **tab, char **tetri, t_fil *fil)
{
	t_tetri	tet;

	tet.tetri = tetri;
	tet.tetri_y = 0;
	while (tet.tetri[tet.tetri_y] != 0)
		tet.tetri_y++;
	tet.tetri_x = 0;
	while (tet.tetri[0][tet.tetri_x] != '\0')
		tet.tetri_x++;
	tet.map = cutmap(tab, fil);
	if (fil->start > fil->line / 2 + fil->line / 10)
		strat_down(fil, tet);
	else
		strat_up(fil, tet);
	freetab(tet.map);
}

void		first_move(t_fil *fil, char **tab)
{
	char	**tetri;

	if (!(tetri = ft_readpiece()))
		exit(EXIT_FAILURE);
	puttetri(tab, tetri, fil);
	freetab(tetri);
}
