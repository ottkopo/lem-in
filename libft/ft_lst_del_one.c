/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:25:25 by akoykka           #+#    #+#             */
/*   Updated: 2022/06/30 14:00:48 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lst_del_one(t_list **head, t_list *target, \
		void (*del)(void*, size_t))
{
	t_list	*temp;

	if (!head || !del || target)
		return ;
	if (!*head)
		return ;
	temp = *head;
	while (temp->next != target && temp->next)
	{
		temp = temp->next;
	}
	del(target->content, target->content_size);
	temp->next = target->next;
	free(target);
	target = NULL;
}
