/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:12:36 by akoykka           #+#    #+#             */
/*   Updated: 2022/06/03 09:42:43 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		found;
	char	*lastseen;

	found = 0;
	while (*s != '\0')
	{
		if (c == *s)
		{
			lastseen = (char *) s;
			found = 1;
		}
		++s;
	}
	if (c == 0)
		return ((char *) s);
	if (found == 1)
		return (lastseen);
	return (NULL);
}
