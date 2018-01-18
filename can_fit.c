/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_fit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 06:44:57 by dhuber            #+#    #+#             */
/*   Updated: 2017/12/07 14:51:09 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "fillit.h"

void	delete(t_tetri *list, char *map)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (map[i] == list->letter)
			map[i] = '.';
		i++;
	}
}

void	fill(t_tetri *list, char *map, int size, int pos)
{
	int i;

	i = 0;
	while (map[pos] && list->tetri[i])
	{
		if (list->tetri[i] == '\n')
		{
			i++;
			pos = pos + size - 3;
		}
		if (list->tetri[i] == list->letter && map[pos] == '.')
			map[pos] = list->letter;
		i++;
		pos++;
	}
}

int		fit(t_tetri *list, char *map, int size, int pos)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (map[pos] && list->tetri[i])
	{
		if (list->tetri[i] == '\n')
		{
			i++;
			pos = pos + size - 3;
		}
		if (list->tetri[i] == list->letter && map[pos] == '.')
		{
			count++;
			if (count == 4)
				return (1);
		}
		i++;
		pos++;
	}
	return (0);
}

int		can_fit(t_tetri *list, char *map, int size)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '.' || list->tetri[0] == '.')
			if (fit(list, map, size, i))
				return (1);
		i++;
	}
	return (0);
}
