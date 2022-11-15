/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   march_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:10:37 by okoponen          #+#    #+#             */
/*   Updated: 2022/10/19 20:14:01 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	move_all_ants(t_path *data, char **input)
{
	int	i;

	i = 1;
	print_array(input);
	while (i <= data->ant_count)
	{
		write(1, "L", 1);
		ft_putnbr(i);
		write(1, "-", 1);
		ft_putstr(data->end->name);
		if (i < data->ant_count)
			write(1, " ", 1);
		++i;
	}
	write(1, "\n", 1);
}

int	start_is_next_to_end(t_path *data)
{
	int	i;

	i = 0;
	while (i < data->end->link_size)
	{
		if (data->end->links[i]->id == data->start->id)
			return (1);
		++i;
	}
	return (0);
}

void	initialize_march(t_march *march)
{
	march->moves = NULL;
	march->current_link = 0;
	march->ants_marched = 0;
	march->ants_in_end = 0;
	march->buffer = 1000;
	march->written = 0;
}

int	find_path_len(t_path *data, t_march *march)
{
	int	len;
	int	i;

	len = 0;
	i = march->current_link;
	while (data->winner[i] != data->start->id)
	{
		i = data->winner[i];
		len++;
	}
	return (len + 1);
}
