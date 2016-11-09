/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:58:01 by ryaoi             #+#    #+#             */
/*   Updated: 2016/11/09 13:42:48 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

int		check(char *stock);

char	*read_stock(int	fd)
{
	int		f;
	int		i;
	char	c;
	char	*line;

	printf("start open\n");
	line = NULL;
	i = 0;
	f = read(fd, &c, 1);
	if (fd < 0)
		return (NULL);
	if (f == 1)
	{
		line = (char *)malloc(sizeof(char));
		while (f != '\0')
		{
			line[i] = c;
			i++;
			f = read(fd, &c, 1);
		}
		line[i] = '\0';
	}
	return (line);
}

int		main(int argc, char **argv)
{
	char	*stock;
	int		fd;
	int		i;

	if (argc != 2)
	{
		printf("Usage [map]\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	stock = read_stock(fd);
	if (check(stock))
		printf("%s", stock);
	else
		printf("not a good example\n");
	return (0);
}
