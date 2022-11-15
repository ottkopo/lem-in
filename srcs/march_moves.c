/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   march_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:12:13 by okoponen          #+#    #+#             */
/*   Updated: 2022/10/18 14:12:27 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	move_to_end(t_path *data, t_hash *current, t_march *march)
{
	add_move(march, ft_itoa(current->ant), data->end->name);
	current->ant = 0;
	march->ants_in_end++;
}

void	move_to_current(t_path *data, t_hash *current, t_march *march)
{
	if (data->room_list[data->winner[current->id]]->ant != 0)
	{
		current->ant = data->room_list[data->winner[current->id]]->ant;
		data->room_list[data->winner[current->id]]->ant = 0;
		add_move(march, ft_itoa(current->ant), current->name);
	}
}

void	move_from_start(t_path *data, t_hash *curr, t_march *march)
{
	int	path_len;

	path_len = find_path_len(data, march);
	if (march->ants_marched < data->ant_count && data->winner_turns > path_len)
	{
		curr->ant = ++march->ants_marched;
		add_move(march, ft_itoa(curr->ant), curr->name);
	}
}

char	*make_move_str(char *ant, char *node, int move_len)
{
	int		i;
	int		j;
	char	*move;

	i = 0;
	j = 0;
	move = ft_memalloc(sizeof(char) * move_len + 1);
	if (!move)
		error("ERROR: memory allocation failed in make_move_str", 1);
	move[i++] = 'L';
	while (ant[j])
		move[i++] = ant[j++];
	move[i++] = '-';
	j = 0;
	while (node[j])
		move[i++] = node[j++];
	move[i++] = ' ';
	move[i] = '\0';
	return (move);
}

void	add_move(t_march *march, char *ant, char *node)
{
	int		move_len;
	char	*new;
	char	*move;

	new = NULL;
	move = NULL;
	move_len = ft_strlen(ant) + ft_strlen(node) + 3;
	if (ant[0] != '0')
	{
		if (march->buffer < march->written + move_len)
		{
			march->buffer *= 2;
			new = (char *)ft_memalloc(sizeof(char) * (march->buffer + 1));
			if (!new)
				error("ERROR: malloc failed in add move", 1);
			ft_strcpy(new, march->moves);
			free(march->moves);
			march->moves = new;
		}
		move = make_move_str(ant, node, move_len);
		ft_strcat(&march->moves[march->written], move);
	}
	free (ant);
	free (move);
	march->written += move_len;
}
