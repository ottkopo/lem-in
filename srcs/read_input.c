/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:44:48 by akoykka           #+#    #+#             */
/*   Updated: 2022/10/21 16:54:57 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	hash_add_link(t_path *data, char *key1, char *key2)
{
	t_hash	*room1;
	t_hash	*room2;
	t_hash	**list1;
	t_hash	**list2;

	room1 = hash_get(data, key1);
	room2 = hash_get(data, key2);
	list1 = (t_hash **)ft_memalloc(sizeof(t_hash *) * (room1->link_size + 1));
	list2 = (t_hash **)ft_memalloc(sizeof(t_hash *) * (room2->link_size + 1));
	if (!list1 || !list2)
		error("ERROR: Malloc error (hash_add_link)", 1);
	add_link_to_node(list1, room1->links, room1->link_size);
	add_link_to_node(list2, room2->links, room2->link_size);
	list1[room1->link_size] = room2;
	room1->link_size += 1;
	list2[room2->link_size] = room1;
	room2->link_size += 1;
	room1->links = list1;
	room2->links = list2;
}

int	is_cmd_or_comment(t_path *data, char *line)
{
	static int	start_found;
	static int	end_found;

	if (line[0] == '#')
	{
		if (!ft_strcmp(line, "##start"))
		{
			data->start_id = data->room_count;
			++start_found;
		}
		if (!ft_strcmp(line, "##end"))
		{
			data->end_id = data->room_count;
			++end_found;
		}
		return (1);
	}
	if (line[0] == '#' && line[1] == '#')
		error("ERROR: Too many # in line", 3);
	if (line[0] == 'L')
		error("ERROR: L in input", 4);
	if (start_found == 2 || end_found == 2)
		error("ERROR: Too many end/start nodes", 5);
	return (0);
}

char	**read_input(t_path *data)
{
	char	**lines;
	int		stage;
	int		i;

	i = 0;
	stage = 0;
	lines = allocate_memory(data);
	if (!lines)
		error("ERROR: Line memory allocation failed", 8);
	while (lines[i])
	{
		if (!is_cmd_or_comment(data, lines[i]))
		{
			if (stage == 2)
				parse_link(data, lines[i]);
			if (stage == 1)
				stage = parse_room(data, lines[i]);
			if (stage == 0)
				stage = parse_ants(data, lines[i]);
		}
		++i;
	}
	check_validity(data);
	return (lines);
}

void	print_array(char **array)
{
	while (*array)
	{
		ft_putstr(*array++);
		ft_putchar('\n');
	}
	ft_putchar('\n');
}
