/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 19:10:00 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/19 00:46:25 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	nm_mod_link(t_file *ptr1, t_file *ptr2)
{
	char	*tmp_name;
	char	*tmp_mode;
	int		tmp_link;

	tmp_name = ft_strdup(ptr2->name);
	free(ptr2->name);
	ptr2->name = ft_strdup(ptr1->name);
	free(ptr1->name);
	ptr1->name = ft_strdup(tmp_name);
	free(tmp_name);
	tmp_mode = ft_strdup(ptr1->mode);
	free(ptr1->mode);
	ptr1->mode = ft_strdup(ptr2->mode);
	free(ptr2->mode);
	ptr2->mode = ft_strdup(tmp_mode);
	free(tmp_mode);
	tmp_link = ptr1->link;
	ptr1->link = ptr2->link;
	ptr2->link = tmp_link;
}

static void	us_gp_size(t_file *ptr1, t_file *ptr2)
{
	char	*tmp_us;
	char	*tmp_gp;
	size_t	tmp_size;

	tmp_us = ft_strdup(ptr1->usr_name);
	free(ptr1->usr_name);
	ptr1->usr_name = ft_strdup(ptr2->usr_name);
	free(ptr2->usr_name);
	ptr2->usr_name = ft_strdup(tmp_us);
	free(tmp_us);
	tmp_gp = ft_strdup(ptr1->grp_name);
	free(ptr1->grp_name);
	ptr1->grp_name = ft_strdup(ptr2->grp_name);
	free(ptr2->grp_name);
	ptr2->grp_name = ft_strdup(tmp_gp);
	free(tmp_gp);
	tmp_size = ptr1->size;
	ptr1->size = ptr2->size;
	ptr2->size = tmp_size;
}

static void	md_mod_block(t_file *ptr1, t_file *ptr2)
{
	int		tmp_md;
	char	*tmp_mod;
	int		tmp_block;

	tmp_md = ptr1->md_time;
	ptr1->md_time = ptr2->md_time;
	ptr2->md_time = tmp_md;
	tmp_mod = ft_strdup(ptr1->mod_time);
	free(ptr1->mod_time);
	ptr1->mod_time = ft_strdup(ptr2->mod_time);
	free(ptr2->mod_time);
	ptr2->mod_time = ft_strdup(tmp_mod);
	free(tmp_mod);
	tmp_block = ptr1->block;
	ptr1->block = ptr2->block;
	ptr2->block = tmp_block;
}

static void	linked(t_file *ptr1, t_file *ptr2)
{
	char	*tmp;

	if (ptr1->linked != NULL && ptr2->linked != NULL)
	{
		tmp = ft_strdup(ptr1->linked);
		free(ptr1->linked);
		ptr1->linked = ft_strdup(ptr2->linked);
		free(ptr2->linked);
		ptr2->linked = ft_strdup(tmp);
		free(tmp);
	}
	else if (ptr1->linked != NULL && ptr2->linked == NULL)
	{
		ptr2->linked = ft_strdup(ptr1->linked);
		free(ptr1->linked);
	}
	else if (ptr2->linked != NULL && ptr1->linked == NULL)
	{
		ptr1->linked = ft_strdup(ptr2->linked);
		free(ptr2->linked);
	}
}

void		swap_file(t_file *ptr1, t_file *ptr2)
{
	char	tmp;
	int		tmp_maj;

	tmp_maj = ptr1->maj;
	ptr1->maj = ptr2->maj;
	ptr2->maj = tmp_maj;
	tmp = ptr1->attri;
	ptr1->attri = ptr2->attri;
	ptr2->attri = tmp;
	nm_mod_link(ptr1, ptr2);
	linked(ptr1, ptr2);
	us_gp_size(ptr1, ptr2);
	md_mod_block(ptr1, ptr2);
}
