/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:40:33 by dhuber            #+#    #+#             */
/*   Updated: 2017/12/07 13:06:59 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "fillit.h"

static	int		ft_pt1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '\n')
			return (i);
		i++;
	}
	return (0);
}

static	int		ft_pt2(char *str)
{
	int	i;
	int	hash;

	hash = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '\n' && hash++ > 0)
			return (i);
		i++;
	}
	return (0);
}

static	int		ft_pt3(char *str)
{
	int	i;
	int	hash;

	hash = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '\n' && hash++ > 1)
			return (i);
		i++;
	}
	return (0);
}

static	int		ft_pt4(char *str)
{
	int	i;
	int	hash;

	hash = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '\n' && hash++ > 2)
			return (i);
		i++;
	}
	return (0);
}

char			*ft_get_point(t_tetri *list)
{
	t_point	*point;

	if (!(point = (t_point*)malloc(sizeof(t_point))))
		return (NULL);
	point->pt1 = ft_pt1(list->tetri);
	point->pt2 = ft_pt2(list->tetri);
	point->pt3 = ft_pt3(list->tetri);
	point->pt4 = ft_pt4(list->tetri);
	point = ft_new_point(list->tetri, point);
	return (ft_remake(list->letter, point, list->tetri));
}
