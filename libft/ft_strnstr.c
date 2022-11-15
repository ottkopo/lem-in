/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:30:54 by akoykka           #+#    #+#             */
/*   Updated: 2022/06/03 09:42:43 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	limiter;

	limiter = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && limiter < (int)len)
	{	
		i = 0;
		while (needle[i] == haystack[i] && (i + limiter) < (int)len)
		{
			i++;
			if (!needle[i])
				return ((char *)haystack);
		}
		haystack++;
		limiter++;
	}
	return (NULL);
}
