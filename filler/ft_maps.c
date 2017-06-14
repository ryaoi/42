/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:53:27 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/11 19:42:11 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		get_cord(t_fil *fil, char **map, int *cord)
{
	int			i;
	int			l;

	i = 0;
	*cord = 1;
	if (fil->start == 0)
	{
		while (map[i] != 0)
		{
			l = 0;
			while (map[i][l] != '\0')
			{
				if (map[i][l] == fil->c)
					fil->start = i;
				l++;
			}
			i++;
		}
	}
}

char			**cutmap(char **tab, t_fil *fil)
{
	char		**ret;
	int			i;
	int			skip;
	static int	cord = 0;

	skip = 0;
	i = 0;
	if (!(ret = (char **)malloc(sizeof(char *) * (fil->line + 1))))
		exit(EXIT_FAILURE);
	while (ft_strncmp(tab[i], "00", 2) != 0)
	{
		i++;
		skip++;
	}
	while (i < fil->line + skip)
	{
		ret[i - skip] = ft_strsub(tab[i], 4, ft_strlen(tab[i]) - 4);
		i++;
	}
	ret[i - skip] = 0;
	if (cord == 0)
		get_cord(fil, ret, &cord);
	return (ret);
}
