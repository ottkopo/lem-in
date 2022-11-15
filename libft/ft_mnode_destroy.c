/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mnode_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:39:45 by akoykka           #+#    #+#             */
/*   Updated: 2022/06/22 10:45:24 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_mnode_destroy(t_mnode **root)
{
	size_t	i;

	i = 0;
	if (!root || !*root)
		return ;
	while (i < (*root)->next_size)
	{
		ft_mnode_destroy(&((*root)->next)[i]);
		++i;
	}
	if ((*root)->content != NULL)
	{
		ft_memdel(&((*root)->content));
	}
	ft_memdel((void *)root);
}
