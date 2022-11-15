/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:18:23 by akoykka           #+#    #+#             */
/*   Updated: 2022/07/15 19:07:27 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_whtspc(char c)
{
	if ((c <= 13 && c >= 9) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	a;
	int	negative;

	negative = 1;
	a = 0;
	i = 0;
	while (ft_whtspc(str[i]) == 1)
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			negative = -1;
		}
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{	
		a = a * 10 + (str[i] - '0');
		++i;
	}
	return (a * negative);
}
