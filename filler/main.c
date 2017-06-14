/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:32:12 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/11 19:45:26 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_fil	fil;
	char	**tab;

	ft_player(&fil);
	while (1)
	{
		if (!(tab = ft_readmap(&fil)))
			exit(EXIT_FAILURE);
		first_move(&fil, tab);
		freetab(tab);
	}
	return (0);
}
