/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:04:21 by akoykka           #+#    #+#             */
/*   Updated: 2022/06/03 09:42:43 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_iswhitespace(char c)
{
	if (c == 32 || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static int	ft_len(char const *s, int start)
{
	int	i;

	i = (int)ft_strlen(s);
	while (ft_iswhitespace(s[i - 1]) == 1)
		--i;
	if ((i - start) < 0)
		return (0);
	return (i - start);
}

static int	ft_start(char const *s)
{
	int	i;

	i = 0;
	while (ft_iswhitespace(s[i]))
		++i;
	return (i);
}

char	*ft_strtrim(char const *s)
{
	unsigned int	start_i;
	size_t			len;

	if (!s)
		return (NULL);
	len = (size_t)ft_len(s, ft_start(s));
	start_i = (unsigned int)ft_start(s);
	return (ft_strsub(s, start_i, len));
}
