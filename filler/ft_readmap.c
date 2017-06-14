/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:30:30 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/11 19:46:08 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		**ft_readpiece(void)
{
	int			piece;
	char		**tetri;
	char		*line;
	int			i;

	get_next_line(0, &line);
	piece = ft_atoi(line + 6);
	if (!(tetri = (char **)malloc(sizeof(char *) * piece + 1)))
		return (NULL);
	i = 0;
	ft_strdel(&line);
	while (i < piece)
	{
		get_next_line(0, &line);
		if (line != NULL)
		{
			tetri[i] = ft_strdup(line);
			ft_strdel(&line);
		}
		i++;
	}
	tetri[i] = 0;
	return (tetri);
}

char		**ft_readmap(t_fil *fil)
{
	int			i;
	char		**map;
	char		*line;
	static int	max = 0;

	line = NULL;
	if (max == 0)
		max = fil->line + 1;
	else
		max = fil->line + 2;
	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * max + 1)))
		return (NULL);
	while (i < max)
	{
		get_next_line(0, &line);
		if (line != NULL)
		{
			map[i] = ft_strdup(line);
			ft_strdel(&line);
		}
		i++;
	}
	map[i] = 0;
	return (map);
}
