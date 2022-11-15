/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mnode_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:40:50 by akoykka           #+#    #+#             */
/*   Updated: 2022/06/22 10:45:22 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_mnode	*ft_mnode_new(void const *content, size_t content_size)
{
	t_mnode	*fresh;

	fresh = (t_mnode *)ft_memalloc(sizeof(t_mnode));
	if (!fresh)
		return (NULL);
	fresh->next_size = 0;
	fresh->content_size = 0;
	fresh->content = NULL;
	fresh->next = NULL;
	if (content != NULL)
	{
		fresh->content = (void *)ft_memalloc(content_size);
		if (!fresh->content)
		{
			free(fresh);
			return (NULL);
		}
		ft_memcpy(fresh->content, content, content_size);
		fresh->content_size = content_size;
	}
	return (fresh);
}
