/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:15:46 by ryaoi             #+#    #+#             */
/*   Updated: 2016/11/22 19:39:05 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int			main(int argc, char **argv)
{
	char	*stock;
	int		fd;
	t_tetri	*tetri;

	if (argc != 2)
	{
		ft_putendl("usage input_file");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 1)
		exit(EXIT_FAILURE);
	if (!check_str(stock = stock_str(fd)))
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
	close(fd);
	tetri = stock_tetri(stock);
	if (tetri == NULL)
		exit(EXIT_FAILURE);
	solve(tetri);
	free(tetri);
	free(stock);
	exit(EXIT_SUCCESS);
}
