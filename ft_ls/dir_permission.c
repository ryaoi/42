/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_permission.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:31:28 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/08 18:18:38 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		check_denied(char *str, t_list *origin, t_list **lst)
{
	struct stat		fs;

	if (lstat(str, &fs) < 0)
		exit(EXIT_FAILURE);
	if ((fs.st_mode & S_IXUSR) == 0 && (S_ISDIR(fs.st_mode)))
	{
		if (origin->next != NULL)
			ft_printf("%s:\n", str);
		ft_printf("ft_ls: %s: Permission denied\n", str);
		(*lst)->d = 5;
		newline(origin);
	}
}
