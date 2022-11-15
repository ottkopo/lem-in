/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:54:59 by okoponen          #+#    #+#             */
/*   Updated: 2022/10/19 16:06:39 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	error(char *error_msg, int exit_code)
{
	ft_putstr(error_msg);
	ft_putchar('\n');
	exit (exit_code);
}

void	print_usage(void)
{
	ft_putstr("Usage: ./lem-in -flags < [map_file]\n");
	exit (0);
}

void	check_validity(t_path *data)
{
	if (data->room_count == 1)
		error("ERROR: No rooms", 21);
	if (data->ant_count == 0)
		error("ERROR: No ants", 7);
	if (data->room_count == 0)
		error("ERROR: No nodes", 9);
	if (data->end_id == 0)
		error("ERROR: No end node", 10);
	if (data->start_id == 0)
		error("ERROR: No start node", 11);
	if (data->room_list[data->end_id]->link_size == 0)
		error("ERROR: End node has no links", 12);
	if (data->room_list[data->start_id]->link_size == 0)
		error("ERROR: Start node has no links", 13);
}
