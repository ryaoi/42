/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:16:29 by ryaoi             #+#    #+#             */
/*   Updated: 2016/11/09 14:59:11 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		check_connected(char *stock, int j)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (i + j < 20 + j)
	{
		if (stock[i + j] == '#')
		{
			if ((i + j + 1) < (20 + j) && stock[i + j + 1] == '#')
				count++;
			if ((i + j - 1) >= (0 + j) && stock[i + j - 1] == '#')
				count++;
			if ((i + j + 5) < (20 + j) && stock[i + j + 5] == '#')
				count++;
			if ((i + j - 5) >= (0 + j) && stock[i + j - 5] == '#')
				count++;
		}
		i++;
	}
	printf("count : %d\n", count);
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

int		check_valid_char(char *stock, int j)
{
	int i;

	i = 0;
	while (i + j < 20 + j)
	{
		if (stock[i + j] != '.' && stock[i + j] != '#' && stock[i + j] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int		count_valid_char(char *stock, int j)
{
	int dash;
	int dot;
	int newline;
	int i;

	i = 0;
	dash = 0;
	dot = 0;
	newline = 0;
	while (i + j < 20 + j)
	{
		if (stock[i + j] == '#')
			dash++;
		if (stock[i + j] == '.')
			dot++;
		if (stock[i + j] == '\n')
			newline++;
		i++;
	}
	if (dash == 4 && dot == 12 && newline == 4)
		return (1);
	return (0);
}
int		check(char *stock)
{
	int i;
	int j;

	i = 0;
	j = 0;
/*
 *
	while (stock[i] != '\0')
	{
		printf("for %d stock is : %c \n", i, stock[i]);
		i++;
	}
	i = 0;
*/
	while (stock[i + j] != '\0')
	{
		if (!(check_connected(stock, j) && check_valid_char(stock, j)
					&& count_valid_char(stock, j)))
			return (0);
		i = 19;
		if (stock[i + j] == '\n' && stock[i + j + 1] == '\0')
			return (1);
		if (stock[i + j] == '\n' && stock[i + j + 1] == '\n'
				&& (stock[i + j + 2] == '.' || stock[i + j + 2] == '#'))
			j += 21;
		else
			return (0);
		i = 0;
	}
	return (1);
}
