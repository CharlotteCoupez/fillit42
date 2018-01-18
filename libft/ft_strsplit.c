/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:01:42 by dhuber            #+#    #+#             */
/*   Updated: 2017/11/27 17:16:30 by dhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_is_c(char s, char c)
{
	return ((s == c) ? 1 : 0);
}

static	char	*ft_copy(char const *src, size_t len)
{
	char	*ptr;
	size_t	index;

	index = 0;
	ptr = ft_memalloc(len + 1);
	if (!ptr)
		return (NULL);
	while (src[index] && index < len)
	{
		ptr[index] = src[index];
		index++;
	}
	return (ptr);
}

static	size_t	ft_len(char const *s, char c)
{
	size_t	index;

	index = 0;
	while (!ft_is_c(s[index], c))
		index++;
	return (index);
}

static	size_t	ft_words(char const *s, char c)
{
	size_t	index;
	size_t	words;

	index = 0;
	words = 0;
	if (*s == 0)
		return (0);
	while (s[index])
	{
		if (!ft_is_c(s[index], c) && ft_is_c(s[index + 1], c))
			words++;
		index++;
	}
	if (!ft_is_c(s[index - 1], c))
		words++;
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ptr;
	size_t	len_w;
	size_t	index_s;
	size_t	index_ptr;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_words(s, c);
	if (!(ptr = (char**)ft_memalloc(sizeof(char*) * (words + 1))))
		return (NULL);
	index_s = 0;
	index_ptr = 0;
	while (words--)
	{
		while (ft_is_c(s[index_s], c))
			index_s++;
		len_w = ft_len(&s[index_s], c);
		ptr[index_ptr] = ft_copy(&s[index_s], len_w);
		index_s += len_w;
		index_ptr++;
	}
	return (ptr);
}
