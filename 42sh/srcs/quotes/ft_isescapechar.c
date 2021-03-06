/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isescapechar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 22:21:51 by ryaoi             #+#    #+#             */
/*   Updated: 2017/04/03 22:25:09 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_isescapechar(char c)
{
	return ((c == 't' || c == 'a' || c == 'b' ||
			c == 'c' || c == 'e' || c == 'f' || c == 'n'
			|| c == 'r' || c == 'v') || c == '\n');
}
