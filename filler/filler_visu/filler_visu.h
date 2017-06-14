/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_visu.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 04:48:28 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/09 09:45:44 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_VISU_H
# define FILLER_VISU_H

# include <mlx.h>
# include "../libft/libft.h"
# include <math.h>

# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define LIME 0x0000FF00
# define BLUE 0x000000FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF
# define MAGENTA 0x00FF00FF

typedef struct		s_plat
{
	int				map_col;
	int				map_line;
	int				win_o;
	int				win_x;
}					t_plat;

typedef struct		s_page
{
	char			**line;
	struct s_page	*next;
	struct s_page	*prev;
}					t_page;

typedef struct		s_mw
{
	void			*mlx;
	void			*win;
	void			*img_ptr;
	char			*data;
	t_page			*page_ptr;
	t_page			*end;
	t_page			*start;
	int				win_x;
	int				win_y;
	int				get_o;
	int				get_x;
	int				multi_ratio;
	int				once;
}					t_mw;

void				print_elem_dot(int counter, int i, t_mw *mw);
void				print_elem_o(int counter, int i, t_mw *mw);
void				print_elem_x(int counter, int i, t_mw *mw);
void				print_elem_capo(int counter, int i, t_mw *mw);
void				print_elem_capx(int counter, int i, t_mw *mw);
void				cont_page(t_page **begin, char *line, t_plat *plat);
void				init_page(t_page **begin, char *line, t_plat plat);
void				print_filler(t_page *page_ptr, t_mw *mw, int counter);
void				end_start(t_mw *mw);
void				free_page(t_page **begin);
void				header_filler(t_mw *mw);
void				e_mlx(t_mw *mw, int i, int l);
void				r_mlx(t_mw *mw);

#endif
