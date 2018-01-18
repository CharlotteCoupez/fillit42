/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:42:34 by dhuber            #+#    #+#             */
/*   Updated: 2017/11/22 20:16:37 by dhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_print_bit(int n)
{
	static char	tab[16];
	int			x;

	x = 0;
	while (x < 16)
	{
		tab[x++] = n & 0x8000 ? '1' : '0';
		n = n << 1;
	}
	tab[x] = '\0';
	return (tab);
}
