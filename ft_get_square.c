/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:39:13 by ccoupez           #+#    #+#             */
/*   Updated: 2017/12/07 14:34:52 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "fillit.h"

char	*backtracking(t_tetri *list, char *map, int size)
{
	int		i;

	i = 0;
	if (!list)
		return (map);
	if (can_fit(list, map, size) == 1 && map[i])
	{
		while (map[i])
		{
			if (fit(list, map, size, i))
			{
				fill(list, map, size, i);
				if (backtracking(list->next, map, size))
					return (map);
				else
					delete(list, map);
			}
			i++;
		}
	}
	return (NULL);
}

char	*algorithm(t_tetri *list)
{
	int		size;
	char	*map;

	size = size_map(list);
	map = create_map(size);
	while (!backtracking(list, map, size))
	{
		size++;
		free(map);
		map = create_map(size);
	}
	return (map);
}
