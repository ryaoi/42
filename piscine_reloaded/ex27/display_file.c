/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:13:23 by ryaoi             #+#    #+#             */
/*   Updated: 2016/11/06 15:13:24 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	display_file(char *argv)
{
	int		fd;
	int		read_it;
	char	c;

	fd = open(argv, O_RDONLY);
	while ((read_it = read(fd, &c, 1)))
		write(1, &c, read_it);
	close(fd);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		write(1, "File name missing.\n", 19);
	if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	if (argc == 2)
		display_file(argv[1]);
	return (0);
}
