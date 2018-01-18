/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:58:32 by dhuber            #+#    #+#             */
/*   Updated: 2017/11/16 14:26:50 by dhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	while (s[i])
		i++;
	if (!(ptr = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (*s)
		ptr[i++] = (*f)(*(char*)s++);
	ptr[i] = '\0';
	return (ptr);
}
