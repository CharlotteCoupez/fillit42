/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:11:30 by ccoupez           #+#    #+#             */
/*   Updated: 2017/12/07 14:31:10 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_position(char *buf)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (buf[++i])
	{
		if (buf[i] == '#' && buf[i + 1] == '#' && i < 20)
			count++;
		if (buf[i] == '#' && buf[i + 5] == '#' && i < 16)
			count++;
		if (buf[i] == '#' && buf[i - 1] == '#' && i > 0)
			count++;
		if (buf[i] == '#' && buf[i - 5] == '#' && i > 4)
			count++;
		if ((i == 20 && buf[i + 1] != '\0') || (i == 19 && buf[i + 1] == '\0'))
		{
			if (count != 6 && count != 8)
				return (FAIL);
			buf = buf + i + 1;
			i = -1;
			count = 0;
		}
	}
	return (SUCCESS);
}

static int	check_new_line(char *buf)
{
	int i;
	int	new_line;

	i = 0;
	new_line = 0;
	while (buf[i])
	{
		if (buf[i] == '\n' && (i % 5 == 4 || i % 20 == 0))
		{
			new_line++;
			if (i == 20 && buf[i + 1] != '\0')
			{
				buf = buf + i + 1;
				i = -1;
			}
		}
		i++;
	}
	if ((new_line + 1) % 5 != 0)
		return (FAIL);
	return (SUCCESS);
}

int			check_char_tetri(char *buf)
{
	int		i;
	int		point;
	int		hash;
	int		nl;
	int		tetri;

	if (!buf)
		return (FAIL);
	i = 0;
	point = 0;
	hash = 0;
	nl = check_new_line(buf);
	tetri = check_position(buf);
	while (buf[i])
	{
		if (buf[i] == '.')
			point++;
		if (buf[i] == '#')
			hash++;
		i++;
	}
	if (point % 12 != 0 || hash % 4 != 0 || (i + 1) % 21 != 0 ||
			nl == FAIL || tetri == FAIL)
		return (FAIL);
	return (SUCCESS);
}
