/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:26:56 by akoykka           #+#    #+#             */
/*   Updated: 2022/10/21 16:06:21 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/queue.h"

int	parse_ants(t_path *data, char *str)
{
	if (ft_isint(str) && ft_atoi(str) > 0)
		data->ant_count = ft_atoi(str);
	else
		error("ERROR: Incorrect ant format", 1);
	return (1);
}

int	parse_room(t_path *data, char *line)
{
	char	**info;

	info = ft_strsplit(line, ' ');
	if (ft_array_len(info) == 3 && ft_isint(info[1]) && ft_isint(info[2]))
	{
		hash_add(data, info[0], ft_atoi(info[1]), ft_atoi(info[2]));
		data->room_count++;
	}
	else
	{
		ft_free_array(info);
		parse_link(data, line);
		return (2);
	}
	ft_free_array(info);
	return (1);
}

void	parse_link(t_path *data, char *str)
{
	char	**link;

	if (ft_strstr(str, "--"))
		error("ERROR: Too many dashes in link", 72);
	link = ft_strsplit(str, '-');
	if (!link)
		error("ERROR: memory allocation failed in parse_link", 2);
	if (ft_array_len(link) == 2 && hash_djb2(link[0]) && hash_djb2(link[1]))
		hash_add_link(data, link[0], link[1]);
	else
	{
		ft_free_array(link);
		error("ERROR: Invalid Room/Link", 2);
	}
	ft_free_array(link);
}
