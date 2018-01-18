/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:11:38 by ccoupez           #+#    #+#             */
/*   Updated: 2017/12/12 15:17:19 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "fillit.h"

int		main(int argc, char **argv)
{
	char	buf[BUF_SIZE];
	char	*final_map;
	t_tetri	*list;

	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file\n");
		return (0);
	}
	else
	{
		if (check_char_tetri(ft_get_file(argv[1], buf)) == FAIL)
		{
			ft_putstr("error\n");
			return (0);
		}
		else
		{
			list = ft_split_in_list(buf);
			list = ft_put_left(list);
			final_map = algorithm(list);
			ft_putstr(final_map);
		}
	}
	return (0);
}
