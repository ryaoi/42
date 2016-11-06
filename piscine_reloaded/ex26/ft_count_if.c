/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:13:06 by ryaoi             #+#    #+#             */
/*   Updated: 2016/11/06 15:13:08 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char *))
{
	int		result;
	int		i;

	result = 0;
	i = 0;
	while (tab[i] != '\0')
	{
		if ((*f)(tab[i]) == 1)
			result++;
		i++;
	}
	return (result);
}
