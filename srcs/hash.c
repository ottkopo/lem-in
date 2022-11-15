/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:11:10 by akoykka           #+#    #+#             */
/*   Updated: 2022/10/21 15:53:05 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

unsigned long	hash_djb2(char *str)
{
	unsigned long	hash;
	int				c;

	hash = 5381;
	while (*str)
	{
		c = *str;
		hash = ((hash << 5) + hash) + c;
		++str;
	}
	return (hash);
}

t_hash	*hash_get(t_path *data, char *key)
{
	unsigned long	digest;

	digest = hash_djb2(key) % data->table_size;
	if (!data->hash_table[digest])
		error("ERROR: no such link", 19);
	while (ft_strcmp(key, data->hash_table[digest]->name))
	{
		++digest;
		if (digest == data->table_size)
			digest = 0;
		if (!data->hash_table[digest])
			error("ERROR: no such link", 19);
	}
	return (data->hash_table[digest]);
}

void	hash_add(t_path *data, char *name, int x, int y)
{
	unsigned long	digest;

	digest = hash_djb2(name) % data->table_size;
	while (data->hash_table[digest])
	{
		if (!ft_strcmp(data->hash_table[digest]->name, name))
			error("ERROR: Duplicate room", 20);
		digest++;
		if (data->table_size == digest)
			digest = 0;
	}
	data->hash_table[digest] = (t_hash *)ft_memalloc(sizeof(t_hash));
	if (!data->hash_table[digest])
		exit(1);
	data->hash_table[digest]->name = ft_strdup(name);
	data->hash_table[digest]->links = NULL;
	if (!data->hash_table[digest]->name)
		error("Error, malloc (hash_add)", 1);
	data->hash_table[digest]->id = data->room_count;
	data->hash_table[digest]->xy[0] = x;
	data->hash_table[digest]->xy[1] = y;
	data->hash_table[digest]->link_size = 0;
	data->room_list[data->room_count] = data->hash_table[digest];
}
