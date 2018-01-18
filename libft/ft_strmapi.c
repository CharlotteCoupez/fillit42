/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:27:52 by dhuber            #+#    #+#             */
/*   Updated: 2017/11/16 15:24:20 by dhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	int		len;
	char	*ptr;

	len = 0;
	index = 0;
	if (!s || !f)
		return (NULL);
	while (s[len])
		len++;
	if (!(ptr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	while (*s)
		ptr[len++] = (*f)(index++, *(char*)s++);
	ptr[len] = '\0';
	return (ptr);
}
