/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moska <moska@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:13:47 by moska             #+#    #+#             */
/*   Updated: 2017/04/05 14:39:51 by tmoska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str2del(char ***tab)
{
	int i;

	i = 0;
	if (!tab && !(*tab))
		return ;
	while (*tab && (*tab)[i])
	{
		ft_strdel(&((*tab)[i]));
		i++;
	}
	free(*tab);
}