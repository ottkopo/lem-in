/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:10:23 by akoykka           #+#    #+#             */
/*   Updated: 2022/10/19 16:59:03 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	allocate_memory_for_bfs(t_path *data)
{
	data->start = data->room_list[data->start_id];
	data->end = data->room_list[data->end_id];
	data->winner_turns = -1;
	data->winner = (int *)ft_memalloc(sizeof(int) * data->room_count);
	data->edges = (int *)ft_memalloc(sizeof(int) * data->room_count);
	data->flow = (int *)ft_memalloc(sizeof(int) * data->room_count);
	data->visit = (int *)ft_memalloc(sizeof(int) * data->room_count);
	if (!data->winner || !data->flow || !data->edges || !data->visit)
		exit(1);
}

void	reset_values(t_path *data)
{
	ft_bzero(data->edges, sizeof(int) * data->room_count);
	ft_bzero(data->visit, sizeof(int) * data->room_count);
	q_add_queue(data->room_count);
	q_enqueue(data->start->id);
	data->visit[data->start->id] = 1;
	data->edges[data->start->id] = data->start->id;
}
