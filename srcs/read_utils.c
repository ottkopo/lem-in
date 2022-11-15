/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:19:27 by akoykka           #+#    #+#             */
/*   Updated: 2022/10/21 16:57:59 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	read_stdin(char *buf)
{
	int	ret;

	ret = 0;
	ft_memset(buf, 0, sizeof(char) * 1000 + 1);
	ret = read(0, buf, 1000);
	if (ret == -1)
		print_usage();
	return (ret);
}

char	*memory_realloc(char *src, char *src2)
{
	unsigned int	len;
	char			*new;

	new = NULL;
	len = 0;
	if (src)
		len += ft_strlen(src);
	if (src2)
		len += ft_strlen(src2);
	new = (char *)ft_memalloc(sizeof(char) * len + 1);
	if (!new)
		exit(1);
	if (src)
		ft_strcat(new, src);
	if (src2)
		ft_strcat(new, src2);
	return (new);
}

char	*get_stdin_input(void)
{
	char	*line;
	char	buf[1000 + 1];
	int		ret;
	char	*free_er;

	ret = 0;
	line = NULL;
	ret = read_stdin(buf);
	if (ret == 0)
		error("ERROR: Input missing", 42);
	while (ret)
	{	
		free_er = line;
		line = memory_realloc(line, buf);
		free(free_er);
		free_er = NULL;
		ret = read_stdin(buf);
	}
	if (!is_valid_input(line))
		error("ERROR: invalid_input", 14);
	return (line);
}

void	add_link_to_node(t_hash **dst, t_hash **src, int size)
{
	int	i;

	i = 0;
	while (size--)
	{
		dst[i] = src[i];
		++i;
	}
	free(src);
	src = NULL;
}

char	**allocate_memory(t_path *data)
{
	char	**lines;
	char	*bigline;
	int		len;

	lines = NULL;
	bigline = get_stdin_input();
	lines = ft_strsplit(bigline, '\n');
	len = ft_array_len(lines);
	data->hash_table = (t_hash **)ft_memalloc(sizeof(t_hash *) * (len * 3));
	data->room_list = (t_hash **)ft_memalloc(sizeof(t_hash *) * (len + 1));
	data->table_size = len * 3;
	if (!data->room_list || !data->hash_table)
		error("ERROR: memory allocation fail", 1);
	data->room_count = 1;
	free(bigline);
	return (lines);
}
