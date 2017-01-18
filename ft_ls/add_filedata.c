/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 13:12:13 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/08 19:52:13 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_usrgrp_size_time(struct stat fs, t_file **new)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid(fs.st_uid);
	grp = getgrgid(fs.st_gid);
	(*new)->usr_name = ft_strdup(pwd->pw_name);
	(*new)->grp_name = ft_strdup(grp->gr_name);
	if ((*new)->mode[0] == 'c' || (*new)->mode[0] == 'b')
	{
		(*new)->maj = major(fs.st_rdev);
		(*new)->size = minor(fs.st_rdev);
	}
	else
	{
		(*new)->maj = 0;
		(*new)->size = (intmax_t)fs.st_size;
	}
	(*new)->md_time = fs.st_mtime;
}

static void			ft_st_mode(struct stat fs, t_file **new,
					char *path)
{
	size_t			len;
	char			buf[250];

	(*new)->linked = ft_strdup("no_link");
	if (S_ISDIR(fs.st_mode))
		(*new)->mode[0] = 'd';
	else if (S_ISLNK(fs.st_mode))
	{
		(*new)->mode[0] = 'l';
		if ((len = readlink(path, buf, sizeof(buf) - 1)))
		{
			buf[len] = '\0';
			free((*new)->linked);
			(*new)->linked = ft_strdup(buf);
		}
	}
	else if (S_ISCHR(fs.st_mode))
		(*new)->mode[0] = 'c';
	else if (S_ISBLK(fs.st_mode))
		(*new)->mode[0] = 'b';
	else if (S_ISFIFO(fs.st_mode))
		(*new)->mode[0] = 'p';
	else
		(*new)->mode[0] = '-';
}

static void			permi(char *name, t_file **new)
{
	struct stat		fs;

	if (lstat(name, &fs) < 0)
		exit(EXIT_FAILURE);
	(*new)->mode = ft_strnew(10);
	find_attr(name, new);
	ft_st_mode(fs, new, name);
	ft_mode(fs, new);
	ft_usrgrp_size_time(fs, new);
	(*new)->block = fs.st_blocks;
}

void				add_filedata(t_file **head, char *name)
{
	t_file			*file;
	t_file			*ptr;

	ptr = *head;
	if (!(file = (t_file *)malloc(sizeof(t_file))))
		exit(EXIT_FAILURE);
	file->name = ft_strdup(name);
	file->next = NULL;
	if (ptr == NULL)
		*head = file;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = file;
	}
	permi(name, &file);
	convert_time(&file);
}
