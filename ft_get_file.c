/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoupez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:32:41 by ccoupez           #+#    #+#             */
/*   Updated: 2017/11/28 12:43:37 by ccoupez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_get_file(char *file, char *buf)
{
	int		fd;
	int		ret;

	if (!(fd = open(file, O_RDONLY)))
		return (NULL);
	if (!(ret = read(fd, buf, BUF_SIZE)))
	{
		close(fd);
		return (NULL);
	}
	buf[ret] = '\0';
	if (close(fd) == -1)
		return ("error");
	return (buf);
}
