/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:40:33 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/08 16:40:35 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_user(struct stat fs, t_file **new)
{
	(*new)->mode[1] = (((fs.st_mode & S_IRUSR) ? 'r' : '-'));
	(*new)->mode[2] = (((fs.st_mode & S_IWUSR) ? 'w' : '-'));
	if ((fs.st_mode & S_ISUID) && (fs.st_mode & S_IXUSR))
		(*new)->mode[3] = 's';
	else if (fs.st_mode & S_ISUID)
		(*new)->mode[3] = 'S';
	else
		(*new)->mode[3] = (((fs.st_mode & S_IXUSR) ? 'x' : '-'));
}

static void	ft_grp(struct stat fs, t_file **new)
{
	(*new)->mode[4] = ((fs.st_mode & S_IRGRP) ? 'r' : '-');
	(*new)->mode[5] = ((fs.st_mode & S_IWGRP) ? 'w' : '-');
	if ((fs.st_mode & S_ISGID) && (fs.st_mode & S_IXGRP))
		(*new)->mode[6] = 's';
	else if (fs.st_mode & S_ISGID)
		(*new)->mode[6] = 'S';
	else
		(*new)->mode[6] = ((fs.st_mode & S_IXGRP) ? 'x' : '-');
}

static void	ft_others(struct stat fs, t_file **new)
{
	(*new)->mode[7] = ((fs.st_mode & S_IROTH) ? 'r' : '-');
	(*new)->mode[8] = ((fs.st_mode & S_IWOTH) ? 'w' : '-');
	if ((fs.st_mode & S_ISVTX) && (fs.st_mode & S_IXOTH))
		(*new)->mode[9] = 't';
	else if (fs.st_mode & S_ISVTX)
		(*new)->mode[9] = 'T';
	else
		(*new)->mode[9] = ((fs.st_mode & S_IXOTH) ? 'x' : '-');
	(*new)->mode[10] = '\0';
}

void		ft_mode(struct stat fs, t_file **new)
{
	ft_user(fs, new);
	ft_grp(fs, new);
	ft_others(fs, new);
	(*new)->link = fs.st_nlink;
}
