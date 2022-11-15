/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:03:49 by akoykka           #+#    #+#             */
/*   Updated: 2022/10/19 19:04:54 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/queue.h"

void	q_dequeue(void)
{
	t_qdata	*q;

	q = q_get();
	if (q->size)
	{
		ft_memmove(q->queue, (q->queue + 1), sizeof(int) * q->size);
		--q->size;
		q->queue[q->size] = 0;
	}
}

int	q_peek(void)
{
	t_qdata	*q;

	q = q_get();
	if (!q->size)
	{
		ft_putstr("exiting...is empty (q_peek)\n");
		return (0);
	}
	return (*(q->queue));
}

int	q_is_empty(void)
{
	t_qdata	*q;

	q = q_get();
	if (!q || !q->size)
		return (1);
	return (0);
}

t_qdata	*q_new(unsigned int max_size)
{
	t_qdata	*new;

	new = (t_qdata *)ft_memalloc(sizeof(t_qdata));
	new->queue = ft_memalloc(sizeof(int) * (max_size + 1));
	new->size = 0;
	return (new);
}

void	q_enqueue(int content)
{
	t_qdata	*q;

	q = q_get();
	q->queue[q->size] = content;
	++(q->size);
	q->queue[q->size] = 0;
}
