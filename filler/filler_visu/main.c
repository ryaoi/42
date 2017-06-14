/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 04:36:10 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/09 15:37:27 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visu.h"

static void			key_start_end(int keycode, t_mw *param)
{
	if (keycode == 126)
	{
		if (param->page_ptr->next != NULL)
			param->page_ptr = param->end;
		print_filler(param->page_ptr, param, 0);
	}
	if (keycode == 125)
	{
		param->page_ptr = param->start;
		print_filler(param->page_ptr, param, 0);
	}
	if (keycode == 49)
		ft_printf("result====\nO:%d\nX:%d\n", param->get_o, param->get_x);
}

int					my_key_funct(int keycode, t_mw *param)
{
	if (keycode == 53)
	{
		free_page(&(param->start));
		mlx_destroy_window(param->mlx, param->win);
		exit(0);
	}
	if (keycode == 123)
	{
		if (param->page_ptr->prev != NULL)
			param->page_ptr = param->page_ptr->prev;
		print_filler(param->page_ptr, param, 0);
	}
	if (keycode == 124)
	{
		if (param->page_ptr->next != NULL)
			param->page_ptr = param->page_ptr->next;
		print_filler(param->page_ptr, param, 0);
	}
	key_start_end(keycode, param);
	return (0);
}

static void			init_plat(t_plat *plat, t_mw *mw, char *line)
{
	char			**plat_info;
	int				i;

	plat_info = ft_strsplit(line, ' ');
	plat->map_line = ft_atoi(plat_info[1]);
	plat->map_col = ft_atoi(plat_info[2]);
	if (plat->map_line == 15)
		mw->multi_ratio = 20;
	else if (plat->map_line == 24)
		mw->multi_ratio = 14;
	else
		mw->multi_ratio = 6;
	mw->win_y = (plat->map_line) * mw->multi_ratio + 200;
	mw->win_x = (plat->map_col + 2) * mw->multi_ratio;
	i = 0;
	while (plat_info[i] != 0)
	{
		free(plat_info[i]);
		i++;
	}
	free(plat_info);
}

void				print_filler(t_page *page_ptr, t_mw *mw, int counter)
{
	int				i;

	header_filler(mw);
	ft_printf("\nmap info\n");
	while (page_ptr->line[counter] != 0)
	{
		i = -1;
		ft_printf("%s", page_ptr->line[counter]);
		while (page_ptr->line[counter][++i] != '\0')
		{
			if (page_ptr->line[counter][i] == 'o')
				print_elem_o(counter, i, mw);
			else if (page_ptr->line[counter][i] == 'O')
				print_elem_capo(counter, i, mw);
			else if (page_ptr->line[counter][i] == 'x')
				print_elem_x(counter, i, mw);
			else if (page_ptr->line[counter][i] == 'X')
				print_elem_capx(counter, i, mw);
			else
				print_elem_dot(counter, i, mw);
		}
		ft_printf("\n");
		counter++;
	}
}

int					main(void)
{
	t_mw			mw;
	t_plat			plat;
	char			*line;

	line = ft_strdup("dummy");
	mw.page_ptr = NULL;
	while ((ft_strncmp(line, "Plateau", 7) != 0))
	{
		if (line != NULL)
			ft_strdel(&line);
		get_next_line(0, &line);
	}
	mw.mlx = mlx_init();
	init_plat(&plat, &mw, line);
	mw.win = mlx_new_window(mw.mlx, mw.win_x, mw.win_y, "FILLER");
	ft_strdel(&line);
	init_page(&(mw.page_ptr), line, plat);
	cont_page(&(mw.page_ptr), line, &plat);
	end_start(&mw);
	mw.get_o = plat.win_o;
	mw.get_x = plat.win_x;
	print_filler(mw.page_ptr, &mw, 0);
	mlx_hook(mw.win, 2, 0, my_key_funct, &mw);
	mlx_loop(mw.mlx);
	return (0);
}
