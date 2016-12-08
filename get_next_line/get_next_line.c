/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:44:47 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/08 16:37:43 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int						get_line(char **line, t_line **list)
{
	int					i;

	i = 0;
	while ((*list)->stock[i] != '\0' && (*list)->stock[i] != '\n')
		i++;
	if ((*list)->stock[i] == '\n')
	{
		*line = ft_strsub((*list)->stock, 0, i);
		(*list)->stock = ft_strsub((*list)->stock, i + 1,
		ft_strlen((*list)->stock) - i + 1);
	}
	else if ((*list)->stock[i] == '\0')
	{
		if (i != 0)
			*line = ft_strsub((*list)->stock, 0, i);
		else
			*line = ft_strnew(0);
		(*list)->stock = ft_strnew(0);
		if (i == 0)
		{
			(*list)->fd = 0;
			return (0);
		}
	}
	return (1);
}

t_line					*find_fd(t_line **list, int fd)
{
	t_line				*ptr;

	ptr = *list;
	while (ptr != NULL)
	{
		if (ptr->fd == fd)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

t_line					*new_line(t_line **list, int fd, char *stock)
{
	t_line				*ptr;
	t_line				*new;

	ptr = *list;
	new = (t_line *)malloc(sizeof(t_line));
	new->stock = ft_strdup(stock);
	new->fd = fd;
	if (!ptr)
		*list = new;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
	new->next = NULL;
	return (new);
}

int						my_realloc(const int fd, t_line **list, t_line **ptr)
{
	char				*stock;
	char				*prev;
	char				buffer[BUFF_SIZE + 1];
	int					ret;

	ret = 1;
	stock = ft_strnew(1);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret == -1)
			return (ret);
		buffer[ret] = '\0';
		prev = ft_strdup(stock);
		ft_strdel(&(stock));
		stock = ft_strjoin(prev, buffer);
		ft_strdel(&prev);
	}
	*ptr = new_line(list, fd, stock);
	ft_strdel(&(stock));
	return (ret);
}

int						get_next_line(const int fd, char **line)
{
	static t_line		*list = NULL;
	t_line				*ptr;
	int					ret;

	ret = 1;
	ptr = list;
	if (fd < 0 || (!(line)) || BUFF_SIZE < 1)
		return (-1);
	if (!(*line))
		*line = NULL;
	*line = ft_strnew(0);
	if (!(ptr = find_fd(&list, fd)))
		ret = my_realloc(fd, &list, &ptr);
	if (ret == -1)
		return (ret);
	return (get_line(line, &ptr));
}
