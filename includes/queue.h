/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:40:59 by akoykka           #+#    #+#             */
/*   Updated: 2022/10/19 18:42:59 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H
# include "../libft/includes/libft.h"
# include "lem_in.h"

typedef struct s_qdata
{
	int				*queue;
	unsigned int	size;
}			t_qdata;

typedef struct s_queue_storage
{
	t_qdata			**queue_list;
	int				current_list;
	int				list_size;
}			t_queue_storage;

// INIT
void			q_init(void);
void			q_add_queue(int max_size);
void			q_delete_queue(void);
void			q_destroy(void);

// STORAGE
t_queue_storage	*q_storage(void);
t_qdata			*q_get(void);

// FUNCTIONS
void			q_enqueue(int content);
void			q_dequeue(void);
int				q_peek(void);

int				q_is_empty(void);
void			q_destroy(void);
#endif