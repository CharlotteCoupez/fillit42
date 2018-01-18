/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:59:33 by dhuber            #+#    #+#             */
/*   Updated: 2017/12/07 13:08:52 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "fillit.h"

char		*ft_remake(char letter, t_point *point, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = '.';
		if (i == point->pt1 || i == point->pt2
				|| i == point->pt3 || i == point->pt4)
			str[i] = letter;
		if (i % 5 == 4)
			str[i] = '\n';
		i++;
	}
	return (str);
}

t_point		*ft_new_point(char *str, t_point *point)
{
	int		i;

	i = 0;
	while (str[i])
	{
		while (point->pt1 % 5 != 0 && point->pt2 % 5 != 0
				&& point->pt3 % 5 != 0 && point->pt4 % 5 != 0)
		{
			point->pt1--;
			point->pt2--;
			point->pt3--;
			point->pt4--;
		}
		point->pt1 %= 5;
		if (point->pt2 - 5 > point->pt1)
			point->pt2 -= 5;
		if (point->pt3 - 5 > point->pt2)
			point->pt3 -= 5;
		if (point->pt4 - 5 > point->pt3)
			point->pt4 -= 5;
		i++;
	}
	return (point);
}

t_tetri		*ft_put_left(t_tetri *list)
{
	t_tetri *tmp;

	tmp = list;
	while (tmp)
	{
		tmp->tetri = ft_get_point(tmp);
		tmp = tmp->next;
	}
	return (list);
}
