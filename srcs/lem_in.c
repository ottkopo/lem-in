/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:22:05 by akoykka           #+#    #+#             */
/*   Updated: 2022/10/21 17:01:50 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	apply_rules(t_path *data, int current, int adj_node)
{
	if (!against_flow(data, current, adj_node))
	{
		if (break_flow(data, current, adj_node))
		{
			appoint_parent(data, current, adj_node);
			visit(data, data->flow[adj_node]);
			return ;
		}
		if (inside_flow(data, current, adj_node))
		{
			visit(data, adj_node);
			return ;
		}
		appoint_parent(data, current, adj_node);
		visit(data, adj_node);
	}
}

void	visit_adj_nodes(t_path *data, int node)
{
	int	i;
	int	adj_node;

	i = 0;
	while (data->room_list[node]->link_size > i)
	{
		adj_node = data->room_list[node]->links[i]->id;
		apply_rules(data, node, adj_node);
		++i;
	}
}

int	augment_paths(t_path *data)
{
	reset_values(data);
	while (!q_is_empty())
	{
		visit_adj_nodes(data, q_peek());
		q_dequeue();
		if (data->edges[data->end->id])
		{
			alter_flow(data);
			q_delete_queue();
			return (1);
		}
	}
	q_delete_queue();
	return (0);
}

void	free_all(t_path *data, char **input)
{
	int	i;

	i = 1;
	while (data->room_count > i)
	{
		free(data->room_list[i]->links);
		free(data->room_list[i]->name);
		free(data->room_list[i]);
		++i;
	}
	free(data->room_list);
	free(data->hash_table);
	free(data->winner);
	free(data->visit);
	free(data->edges);
	free(data->flow);
	q_destroy();
	ft_free_array(input);
}

int	main(void)
{
	t_path	*data;
	char	**input;

	data = (t_path *)ft_memalloc(sizeof(t_path));
	q_init();
	input = read_input(data);
	allocate_memory_for_bfs(data);
	if (start_is_next_to_end(data))
		move_all_ants(data, input);
	else
	{
		while (augment_paths(data))
			get_winner(data);
		if (data->winner_turns == -1)
			error("ERROR: No answer", 52);
		march_ants(data, input);
	}
	free_all(data, input);
	free(data);
	return (0);
}
