/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:26:10 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/08 16:31:02 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			convert_time(t_file **new)
{
	time_t		raw_time;
	char		*str;
	char		*tmp;

	raw_time = (*new)->md_time;
	str = ft_strdup(ctime(&raw_time));
	tmp = ft_strsub(str, 4, 12);
	(*new)->mod_time = ft_strdup(tmp);
	free(str);
	free(tmp);
}
