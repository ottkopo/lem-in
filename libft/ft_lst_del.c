/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:32:36 by akoykka           #+#    #+#             */
/*   Updated: 2022/06/30 12:33:09 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lst_del(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*one_ahead;
	t_list	*current;

	if (!alst || !del)
		return ;
	current = *alst;
	while (current)
	{
		one_ahead = current->next;
		del(current->content, current->content_size);
		free(current);
		current = one_ahead;
	}
	*alst = NULL;
}
