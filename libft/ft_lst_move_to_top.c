/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_move_to_top.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:35:30 by akoykka           #+#    #+#             */
/*   Updated: 2022/06/07 16:45:45 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lst_move_to_top(t_list **head, t_list *target)
{
	t_list	*temp;

	temp = *head;
	if (!head || *head == target)
		return ;
	while (temp)
	{
		if (temp->next == target)
		{
			temp->next = target->next;
			target->next = *head;
			*head = target;
		}
		temp = temp->next;
	}
}
