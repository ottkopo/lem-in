/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:33:16 by akoykka           #+#    #+#             */
/*   Updated: 2022/07/13 17:15:44 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lst_push_top(t_list **src, t_list **dest)
{
	t_list	*target;

	target = *src;
	src = &((*src)->next);
	target->next = *dest;
	dest = &target;
}
