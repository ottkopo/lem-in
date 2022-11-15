/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alter_flow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:55:01 by akoykka           #+#    #+#             */
/*   Updated: 2022/10/19 20:07:00 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	traverse_flow(t_path *data, int node)
{
	t_hash	*temp;
	int		i;

	i = 0;
	temp = data->room_list[node];
	while (node != data->flow[temp->links[i]->id]
		|| data->visit[temp->links[i]->id])
	{
		++i;
		if (temp->link_size < i)
			error("ERROR: flow not found(traverse_flow)", 1);
	}
	return (temp->links[i]->id);
}

int	is_flow(t_path *data, int node)
{
	if (data->flow[node])
		return (1);
	return (0);
}

int	is_edge(t_path *data, int node)
{
	if (data->edges[node])
		return (1);
	return (0);
}

int	backtrack_and_delete_flow(t_path *data, int node)
{
	node = traverse_flow(data, node);
	data->flow[node] = 0;
	return (node);
}

void	alter_flow(t_path *data)
{
	int	node;

	ft_bzero(data->visit, sizeof(int) * data->room_count);
	node = data->edges[data->end->id];
	while (node != data->start->id)
	{
		if (is_flow(data, node))
		{
			node = backtrack_and_delete_flow(data, node);
			while (!is_edge(data, node))
				node = backtrack_and_delete_flow(data, node);
		}
		else
		{
			data->flow[node] = data->edges[node];
			data->visit[node] = 1;
			node = data->edges[node];
		}
	}
}
