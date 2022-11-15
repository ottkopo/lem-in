/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 15:24:46 by akoykka           #+#    #+#             */
/*   Updated: 2022/01/06 22:07:21 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_free(char **first, char **second, int howmanytofree)
{
	if (howmanytofree == 2)
	{
		free(*first);
		free(*second);
		*first = NULL;
		*second = NULL;
	}
	if (howmanytofree == 1)
	{
		free(*first);
		*first = NULL;
	}
	if (howmanytofree == 999)
	{
		free(*first);
		*first = NULL;
		return (999);
	}
	return (-1);
}

static int	ft_cpyend(char **line, char **buf, const int fd)
{
	char	*free_er;

	if (ft_strlen(buf[fd]) == 0 && ft_strlen(*line) == 0)
	{
		free(*line);
		free(buf[fd]);
		*line = NULL;
		buf[fd] = NULL;
		return (0);
	}
	free_er = *line;
	*line = ft_strjoin(*line, buf[fd]);
	if (!*line)
		return (ft_free(&free_er, &buf[fd], 2));
	ft_memset(buf[fd], '\0', (BUFF_SIZE + 1));
	free(free_er);
	return (1);
}

static int	ft_cpy(char **line, char **buf, const int fd)
{
	size_t	len;
	char	*free_er;

	if (!ft_strchr(buf[fd], '\n'))
	{
		free_er = *line;
		*line = ft_strjoin(*line, buf[fd]);
		if (!line)
			return (ft_free(&free_er, &buf[fd], 2));
		ft_memset(buf[fd], '\0', (BUFF_SIZE + 1));
		return (ft_free(&free_er, &buf[fd], 999));
	}	
	free_er = *line;
	*ft_strchr(buf[fd], '\n') = '\0';
	*line = ft_strjoin(*line, buf[fd]);
	ft_free(&free_er, buf, 999);
	if (!*line)
		return (ft_free(&free_er, &buf[fd], 2));
	len = ft_strlen(ft_strchr(buf[fd], '\0') + 1);
	ft_memmove(buf[fd], (ft_strchr(buf[fd], '\0') + 1), len);
	buf[fd][len] = '\0';
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*buf[10240];
	ssize_t		r_value;

	if (!line || fd < 0 || fd > 10239 || BUFF_SIZE < 1)
		return (-1);
	r_value = BUFF_SIZE;
	*line = ft_strnew(0);
	if (!*line)
		return (-1);
	if (!buf[fd])
		buf[fd] = (char *)ft_memalloc(BUFF_SIZE + 1);
	if (!buf[fd])
		return (ft_free(line, &buf[fd], 1));
	while (r_value)
	{
		r_value = ft_cpy(line, buf, fd);
		if (r_value == -1 || r_value == 1)
			return ((int)r_value);
		r_value = read(fd, buf[fd], BUFF_SIZE);
		if (r_value == -1)
			return (ft_free(line, &buf[fd], 2));
	}
	if (ft_strchr(buf[fd], '\n'))
		return (ft_cpy(line, buf, fd));
	return (ft_cpyend(line, buf, fd));
}
