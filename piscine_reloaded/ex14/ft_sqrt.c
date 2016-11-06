/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:10:43 by ryaoi             #+#    #+#             */
/*   Updated: 2016/11/06 15:10:44 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	long	result;

	result = 0;
	while (result * result <= nb)
	{
		if (((result * result) - nb) == 0)
			return (result);
		result++;
	}
	return (0);
}
