/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:04:55 by akoykka           #+#    #+#             */
/*   Updated: 2022/06/07 16:23:20 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_lst_count(t_list *start)
{
	size_t	i;
	t_list	*temp;

	i = 0;
	if (!start)
		return (i);
	temp = start;
	while (temp)
	{
		temp = temp->next;
		++i;
	}
	return (i);
}
