/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_pourcent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:10:25 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/10 18:57:06 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		only_pourcent(const char *format)
{
	if (format == NULL)
		return (0);
	if (ft_strcmp(format, "%") == 0)
		return (0);
	return (2);
}
