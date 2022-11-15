/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:52:56 by akoykka           #+#    #+#             */
/*   Updated: 2022/06/03 09:42:43 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	ft_wordlen(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && ((unsigned char *)str)[i] != (unsigned char)c)
		++i;
	return (i);
}

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			++i;
		else
		{
			++words;
			while (s[i] && ((unsigned char *)s)[i] != (unsigned char)c)
				++i;
		}
	}
	return (words);
}

static void	*ft_freeall(char **ptr, size_t words)
{
	int	i;

	i = 0;
	while (words--)
	{	
		ft_strdel(&ptr[i]);
		++i;
	}
	free(ptr);
	return (NULL);
}

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**index;
	int		j;
	size_t	wordcounter;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	wordcounter = ft_wordcount(s, c);
	index = (char **)ft_memalloc(sizeof(char *) * (wordcounter + 1));
	if (!index)
		return (NULL);
	while (wordcounter > i)
	{
		while (((unsigned char *)s)[j] == (unsigned char)c)
			++j;
		index[i] = ft_strndup(&s[j], ft_wordlen(&s[j], c));
		if (!index[i])
			return (ft_freeall(index, ft_wordcount(s, c)));
		while (s[j] != c && s[j])
			++j;
		++i;
	}
	return (index);
}
