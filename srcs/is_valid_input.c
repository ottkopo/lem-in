/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:20:28 by akoykka           #+#    #+#             */
/*   Updated: 2022/10/21 16:06:57 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	is_empty_lines(char *line)
{
	if (ft_strstr(line, "\n\n"))
		error("ERROR: empty lines in file", 23);
}

size_t	get_room_len(char *room)
{
	size_t	i;

	i = 0;
	while (room[i] && room[i] != '\n')
		++i;
	return (i);
}

int	is_valid_room_next(char *ptr)
{
	char	**array;
	char	*room;

	array = NULL;
	room = NULL;
	while (*ptr && *ptr != '\n')
		++ptr;
	++ptr;
	if (!*ptr || *ptr == '#' || *ptr == 'L')
		return (0);
	room = ft_strndup(ptr, get_room_len(ptr));
	array = ft_strsplit(room, ' ');
	if (ft_array_len(array) == 3 && ft_isint(array[1]) && ft_isint(array[2]))
	{
		free(room);
		ft_free_array(array);
		return (1);
	}
	free(room);
	ft_free_array(array);
	return (0);
}

void	is_valid_start_and_end(char *line)
{
	char	*ptr;

	ptr = ft_strstr(line, "##start\n");
	if (!ptr)
		error("No start found", 31);
	if (!is_valid_room_next(ptr))
		error("ERROR: no valid room for start", 25);
	ptr = ft_strstr(line, "##end\n");
	if (!ptr)
		error("No end found", 31);
	if (!is_valid_room_next(ptr))
		error("ERROR: no valid room for end", 13);
}

int	is_valid_input(char *line)
{
	is_empty_lines(line);
	is_valid_start_and_end(line);
	return (1);
}
