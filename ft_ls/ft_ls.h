/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 15:51:34 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/09 14:17:04 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <fcntl.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include "./ft_printf/ft_printf.h"

typedef	struct		s_opt
{
	size_t			flag_l;
	size_t			flag_capr;
	size_t			flag_a;
	size_t			flag_r;
	size_t			flag_t;
	size_t			flag_g;
	size_t			flag_d;
	size_t			flag_m;
	size_t			solo;
}					t_opt;

typedef	struct		s_list
{
	char			*name;
	int				d;
	struct s_list	*next;
}					t_list;

typedef struct		s_file
{
	char			*name;
	char			attri;
	char			*mode;
	int				link;
	char			*linked;
	char			*usr_name;
	char			*grp_name;
	size_t			maj;
	size_t			size;
	int				md_time;
	char			*mod_time;
	int				block;
	struct s_file	*next;
}					t_file;

void				add_list(t_list **lst, char *str);
void				get_opt(t_opt **opt, int argc, char **argv);
t_opt				*init_opt(void);
void				ft_opt_err(char **argv, t_opt *opt);
void				check_dir(char **argv, t_list **lst, t_opt **opt,
					int *alert);
void				ft_no_opt(char *str, t_opt *opt, int alert);
void				add_file(t_file **head, char *name, char *str);
void				ft_inspect_file(t_file **new, char *name, char *str);
void				convert_time(t_file **new);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					count_digit(int link);
int					count_str(char *str);
void				print_space(int max, int value);
void				ft_opt_l(t_file *head, t_opt *opt);
void				ft_opt(t_file *head);
void				print_id(t_file *head, t_file *origin);
void				print_grp(t_file *head, t_file *origin);
void				print_size(t_file *head, t_file *origin);
void				sort_name(t_file **file);
void				swap_file(t_file *ptr1, t_file *ptr2);
void				sort_time(t_file **file);
void				ft_opt_no_l(t_file *head, t_opt *opt);
void				no_optarg(void);
void				print_space_num(int max, int value);
void				print_space_link(int max, int value, int at);
void				find_attr(char *path, t_file **new);
int					check_attr(t_file *head, t_opt *opt);
void				sort_reverse(t_file **head);
void				print_dir(t_list **lst, t_opt *opt);
void				print_all(t_file *head, t_file *origin, int at, t_opt *opt);
void				add_filedata(t_file **new, char *name);
void				printfiles(t_file *head, t_opt *opt);
void				options(t_file **head, t_opt *opt);
void				check_denied(char *str, t_list *origin, t_list **lst);
void				sort_file(t_file **solo, t_opt *opt);
int					check_bc(t_file *origin);
void				print_maj(t_file *head, t_file *origin);
int					count_file(t_file *head);
int					count_list(t_list *head);
int					count_list_d(t_list *head);
void				ft_opt_d(t_opt **opt);
void				sort_listname(t_list **lst);
void				swap_list(t_list *ptr, t_list *ptr2);
void				ft_recursion(char *str, t_opt *opt);
void				freefile(t_file **head);
void				freelist(t_list	**head);
void				freeonefile(t_file **head);
void				no_argopt(int argc);
void				no_arg(t_list *lst, int alert, t_opt *opt);
int					check_permi(char *str);
void				add_to_solo(t_list **ptr, t_file **solo, int *got_f,
					t_opt *opt);
int					newline(t_list *origin);
void				ft_mode(struct stat fs, t_file **new);

#endif
