/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:33:09 by dhuber            #+#    #+#             */
/*   Updated: 2017/12/07 13:10:51 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "fillit.h"

int		size_map(t_tetri *list)
{
	int		block;
	int		size;
	t_tetri	*tmp;

	size = 0;
	block = 0;
	tmp = list;
	while (tmp)
	{
		tmp = tmp->next;
		block++;
	}
	while (size * size < block * 4)
		size++;
	return (size);
}

char	*create_map(int size)
{
	char	*map;
	int		i;
	int		size_total;

	size_total = size * (size + 1);
	map = ft_strnew(size_total);
	i = 0;
	while (i < size_total)
	{
		if (i % (size + 1) < size)
			map[i] = '.';
		else
			map[i] = '\n';
		i++;
	}
	return (map);
}
