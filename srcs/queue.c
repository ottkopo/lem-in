/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:31:05 by akoykka           #+#    #+#             */
/*   Updated: 2022/10/19 18:59:33 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/queue.h"

void	q_init(void)
{
	t_queue_storage	*temp;

	temp = q_storage();
	temp->queue_list = (t_qdata **)ft_memalloc(sizeof(t_qdata *) * 1000);
	if (!temp->queue_list)
		exit (1);
	temp->list_size = 1000;
	temp->current_list = -1;
}

void	q_add_queue(int size)
{
	t_queue_storage	*temp;
	int				current;

	temp = q_storage();
	++temp->current_list;
	current = temp->current_list;
	temp->queue_list[current] = (t_qdata *)ft_memalloc(sizeof(t_qdata));
	if (!temp->queue_list[current])
		exit (1);
	temp->queue_list[current]->queue = (int *)ft_memalloc(sizeof(int) \
	* (size + 1));
	if (!temp->queue_list[current]->queue)
		exit (1);
	temp->queue_list[current]->size = 0;
}

void	q_delete_queue(void)
{
	t_queue_storage	*temp;

	temp = q_storage();
	if (temp->current_list >= 0)
	{
		free (temp->queue_list[temp->current_list]->queue);
		free (temp->queue_list[temp->current_list]);
		temp->queue_list[temp->current_list] = NULL;
		--temp->current_list;
	}
}
