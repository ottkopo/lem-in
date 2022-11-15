/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:43:41 by akoykka           #+#    #+#             */
/*   Updated: 2022/10/17 22:45:15 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	break_flow(t_path *data, int current, int adj_node)
{
	if (data->flow[adj_node]
		&& data->flow[current] != adj_node)
		return (1);
	return (0);
}

int	inside_flow(t_path *data, int current, int adj_node)
{
	if (data->flow[current] == adj_node)
		return (1);
	return (0);
}

int	against_flow(t_path *data, int current, int adj_node)
{
	if (data->flow[adj_node] == current)
		return (1);
	if (data->flow[current] && adj_node == data->end->id)
		return (1);
	return (0);
}

void	appoint_parent(t_path *data, int current, int adj_node)
{
	if (!data->edges[adj_node])
		data->edges[adj_node] = current;
}

void	visit(t_path *data, int node)
{
	if (!data->visit[node])
	{
		q_enqueue(node);
		data->visit[node] = 1;
	}
}
