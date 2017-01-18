/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_attr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 23:40:43 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/09 13:25:18 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		find_attr(char *path, t_file **new)
{
	ssize_t		xattr;
	acl_t		acl;
	acl_entry_t dummy;

	acl = NULL;
	xattr = 0;
	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (xattr > 0)
		(*new)->attri = '@';
	else if (acl != NULL)
		(*new)->attri = '+';
	else
		(*new)->attri = ' ';
	acl_free(acl);
}

int			check_attr(t_file *head, t_opt *opt)
{
	int			ok;

	opt->flag_a = opt->flag_a;
	ok = 0;
	while (head != NULL)
	{
		if (head->attri == '@' || head->attri == '+')
			ok = 1;
		head = head->next;
	}
	return (ok);
}
