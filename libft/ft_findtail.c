/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findtail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:12:28 by akoykka           #+#    #+#             */
/*   Updated: 2022/06/03 09:37:50 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_findtail(t_list *start)
{
	t_list	*temp;

	if (!start)
		return (NULL);
	temp = start;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}
