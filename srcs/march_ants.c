/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   march_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:47:36 by okoponen          #+#    #+#             */
/*   Updated: 2022/10/21 13:21:42 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	curr_has_ant(t_hash *current)
{
	if (current->ant != 0)
		return (1);
	return (0);
}

int	curr_neighbors_start(t_path *data, t_hash *current)
{
	if (data->winner[current->id] == data->start->id)
		return (1);
	return (0);
}

void	play_one_turn(t_path *data, t_march *march)
{
	int		i;
	int		j;
	t_hash	*curr_node;

	i = -1;
	while (data->end->link_size > ++i)
	{
		j = data->end->links[i]->id;
		if (data->winner[j] != 0)
		{
			march->current_link = j;
			curr_node = data->end->links[i];
			while (curr_node->id != data->start->id)
			{
				if (curr_has_ant(curr_node))
					move_to_end(data, curr_node, march);
				if (curr_neighbors_start(data, curr_node))
					move_from_start(data, curr_node, march);
				else
					move_to_current(data, curr_node, march);
				curr_node = data->room_list[data->winner[j]];
				j = data->winner[j];
			}
		}
	}
}

void	march_ants(t_path *data, char **input)
{
	t_march	march;

	print_array(input);
	initialize_march(&march);
	march.moves = (char *)ft_memalloc(sizeof(char) * march.buffer);
	if (!march.moves)
		error("ERROR: memory allocation failed in march_ants", 1);
	while (data->winner_turns)
	{
		play_one_turn(data, &march);
		if (march.moves[march.written])
			march.moves[march.written] = '\n';
		else
			march.moves[march.written - 1] = '\n';
		data->winner_turns--;
	}
	ft_putstr(march.moves);
	free (march.moves);
}
