/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:31:47 by akoykka           #+#    #+#             */
/*   Updated: 2022/10/17 22:44:06 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	pathlen(int *paths, int node, int start)
{
	int	len;

	len = 0;
	while (node != start)
	{
		node = paths[node];
		++len;
	}
	return (len);
}

int	get_turn_count(int ants, t_turns *turns)
{
	int	ant_leak;

	ant_leak = turns->path_count * turns->longest_len - turns->total_len;
	if (ants - ant_leak <= 0)
		return (9999999);
	if ((ants - ant_leak) % turns->path_count)
		return ((ants - ant_leak) / turns->path_count + 1 + turns->longest_len);
	return ((ants - ant_leak) / turns->path_count + turns->longest_len);
}

int	calc_turns(t_path *data, int *paths)
{
	int		i;
	int		path_len;
	t_turns	turn_count;

	i = 0;
	ft_memset(&turn_count, 0, sizeof(t_turns));
	while (data->end->link_size > i)
	{
		if (paths[data->end->links[i]->id])
		{
			path_len = pathlen(paths, data->end->links[i]->id, data->start->id);
			if (path_len > turn_count.longest_len)
				turn_count.longest_len = path_len;
			turn_count.total_len += path_len;
			++turn_count.path_count;
		}
		++i;
	}
	return (get_turn_count(data->ant_count, &turn_count));
}

void	get_winner(t_path *data)
{
	int	turns;

	turns = calc_turns(data, data->flow);
	if (data->winner_turns == -1
		|| turns < data->winner_turns)
	{
		ft_memmove(data->winner, data->flow, sizeof(int) * data->room_count);
		data->winner_turns = turns;
	}
}
