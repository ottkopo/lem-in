/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:50:18 by akoykka           #+#    #+#             */
/*   Updated: 2022/06/03 09:42:43 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static unsigned int	ft_mallocsize(int c)
{
	unsigned int	negative_or_zero;
	unsigned int	i;

	i = 0;
	negative_or_zero = 0;
	if (c <= 0)
		negative_or_zero = 1;
	while (c != 0)
	{
		c = c / 10;
		++i;
	}
	return (i + negative_or_zero);
}

static char	*ft_minmaxzero(int c)
{
	if (c == -2147483648)
		return ("-2147483648");
	if (c == 2147483647)
		return ("2147483647");
	return ("0");
}

char	*ft_itoa(int n)
{
	char			*answer;
	unsigned int	len;

	len = ft_mallocsize(n);
	answer = (char *)malloc(sizeof(char) * (len + 1));
	if (!answer)
		return (NULL);
	if (n == -2147483648 || n == 2147483647 || n == 0)
		return (ft_strcpy(answer, ft_minmaxzero(n)));
	if (n < 0)
	{
		answer[0] = '-';
		n = n * -1;
	}
	answer[len] = '\0';
	while (n != 0)
	{
		answer[len - 1] = (n % 10 + '0');
		n = n / 10;
		len--;
	}
	return (answer);
}
