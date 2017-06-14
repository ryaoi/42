/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 07:16:26 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/09 08:56:54 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visu.h"

void			end_start(t_mw *mw)
{
	t_page		*ptr;

	ptr = mw->page_ptr;
	mw->start = mw->page_ptr;
	while (ptr->next != NULL)
		ptr = ptr->next;
	mw->end = ptr;
}

void			add_page(t_page **begin, char *line)
{
	t_page		*ptr;
	t_page		*new;

	if (!(new = malloc(sizeof(t_page))))
		exit(EXIT_FAILURE);
	new->next = NULL;
	new->prev = NULL;
	new->line = ft_strsplit(line, '@');
	if (*begin == NULL)
		*begin = new;
	else
	{
		ptr = *begin;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
		new->prev = ptr;
	}
}

void			init_page(t_page **begin, char *line, t_plat plat)
{
	int			counter;
	char		*stock;
	char		*tmp;

	counter = 0;
	stock = NULL;
	get_next_line(0, &line);
	ft_strdel(&line);
	while (counter < plat.map_line)
	{
		get_next_line(0, &line);
		tmp = ft_strsub(line, 4, ft_strlen(line) - 4);
		if (stock == NULL)
			stock = ft_strdup(tmp);
		else
			stock = ft_strjoini(stock, tmp, 1);
		ft_strdel(&line);
		ft_strdel(&tmp);
		stock = ft_strjoini(stock, "@", 1);
		counter++;
	}
	add_page(begin, stock);
	ft_strdel(&stock);
}

void			cont_page(t_page **begin, char *line, t_plat *plat)
{
	line = ft_strdup("bored");
	while (1)
	{
		while ((ft_strncmp(line, "Plateau", 7) != 0) &&
				(ft_strncmp(line, "==", 2) != 0))
		{
			if (line != NULL)
				ft_strdel(&line);
			get_next_line(0, &line);
		}
		if (ft_strncmp(line, "==", 2) == 0)
		{
			plat->win_o = ft_atoi(line + 10);
			ft_strdel(&line);
			get_next_line(0, &line);
			plat->win_x = ft_atoi(line + 10);
			ft_strdel(&line);
			ft_printf("O:%d\nX:%d\n", plat->win_o, plat->win_x);
			return ;
		}
		init_page(begin, line, *plat);
		ft_strdel(&line);
		line = ft_strdup("dump");
	}
}

void			free_page(t_page **begin)
{
	t_page		*ptr;
	t_page		*save;
	int			i;

	ptr = *begin;
	while (ptr != NULL)
	{
		save = ptr->next;
		i = 0;
		while (ptr->line[i] != 0)
		{
			free(ptr->line[i]);
			i++;
		}
		free(ptr->line);
		free(ptr);
		ptr = save;
	}
}
