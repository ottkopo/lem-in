/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:01:16 by akoykka           #+#    #+#             */
/*   Updated: 2022/10/19 19:07:00 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/queue.h"

t_qdata	*q_get(void)
{
	t_queue_storage	*temp;

	temp = q_storage();
	if (temp->current_list < 0)
		return (NULL);
	return ((temp->queue_list)[temp->current_list]);
}

t_queue_storage	*q_storage(void)
{
	static t_queue_storage	storage;

	return (&storage);
}

void	q_destroy(void)
{
	t_queue_storage	*temp;
	unsigned int	i;

	i = 0;
	temp = q_storage();
	if (!temp || !temp->queue_list)
		return ;
	while (q_get())
	{
		free(q_get()->queue);
		free(q_get());
		temp->list_size--;
	}
	free(temp->queue_list);
	temp->queue_list = NULL;
	temp->current_list = 0;
	temp->list_size = 0;
}
