/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 23:07:35 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/08 04:10:46 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	clean_map(char **tab)
{
	int		i;
	int		l;

	i = 0;
	while (tab[i] != 0)
	{
		l = 0;
		while (tab[i][l] != '\0')
		{
			if (tab[i][l] == '*')
				tab[i][l] = '.';
			l++;
		}
		i++;
	}
}

static int	final_return_value(char **tab, int touched, int i, int l)
{
	if (touched != 1)
	{
		clean_map(tab);
		return (0);
	}
	ft_printf("%d %d\n", i, l);
	return (1);
}

static int	processing_check(t_tetri *tet, int i, int l, t_fil *fil)
{
	if (tet->map[i + tet->y][l + tet->x] == fil->c ||
		tet->map[i + tet->y][l + tet->x] == fil->c + 32)
		(tet->touched)++;
	if (tet->touched == 2 || tet->map[i + tet->y][l + tet->x] == fil->enemy_c
		|| tet->map[i + tet->y][l + tet->x] == fil->enemy_c + 32)
	{
		clean_map(tet->map);
		return (0);
	}
	if (tet->map[i + tet->y][l + tet->x] == '.')
		tet->map[i + tet->y][l + tet->x] = tet->tetri[tet->y][tet->x];
	(tet->x)++;
	return (1);
}

int			valid_put(t_tetri tet, int i, int l, t_fil *fil)
{
	tet.touched = 0;
	tet.y = 0;
	while (tet.tetri[tet.y] != 0)
	{
		tet.x = 0;
		while (tet.tetri[tet.y][tet.x] != '\0')
		{
			if (i + tet.y >= fil->line || l + tet.x >= fil->col)
			{
				clean_map(tet.map);
				return (0);
			}
			if (tet.tetri[tet.y][tet.x] == '.')
			{
				(tet.x)++;
				continue ;
			}
			if (processing_check(&tet, i, l, fil) == 0)
				return (0);
		}
		(tet.y)++;
	}
	return (final_return_value(tet.map, tet.touched, i, l));
}
