/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:48:43 by akoykka           #+#    #+#             */
/*   Updated: 2022/10/21 16:59:06 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include "queue.h"

typedef struct s_hash
{
	int				id;
	char			*name;
	int				xy[2];
	int				ant;
	struct s_hash	*parent;
	struct s_hash	**links;
	int				link_size;
}			t_hash;

typedef struct s_path
{
	int				ant_count;
	int				room_count;
	int				start_id;
	int				end_id;
	int				*visit;
	t_hash			*start;
	t_hash			*end;
	t_hash			**room_list;
	t_hash			**hash_table;
	unsigned long	table_size;
	int				*edges;
	int				*flow;
	int				*winner;
	int				winner_turns;
}				t_path;

// HASH
void			hash_add(t_path *data, char *name, int x, int y);
unsigned long	hash_djb2(char *key);
t_hash			*hash_get(t_path *data, char *key);

// READ INPUT
int				is_valid_input(char *line);
char			**read_input(t_path *data);
int				is_cmd_or_comment(t_path *data, char *line);
void			hash_add_link(t_path *data, char *key1, char *key2);
void			add_link_to_node(t_hash **dst, t_hash **src, int size);
void			parse_link(t_path *data, char *str);
int				parse_room(t_path *data, char *line);
int				parse_ants(t_path *data, char *str);
char			*get_stdin_input(void);
char			*memory_realloc(char *src, char *src2);
int				read_stdin(char *buf);
char			**allocate_memory(t_path *data);
void			print_array(char **array);

// AUGMENT_PATHS(BFS) PREPARATION
void			allocate_memory_for_bfs(t_path *data);
void			reset_values(t_path *data);

// AUGMENT PATHS
int				augment_paths(t_path *data);
void			visit_adj_nodes(t_path *data, int node);
int				is_flow(t_path *data, int node);
int				is_edge(t_path *data, int node);
void			visit(t_path *data, int node);

// RULES.C FOR BFS
void			apply_rules(t_path *data, int current, int adj_node);
void			appoint_parent(t_path *data, int current, int adj_node);
int				against_flow(t_path *data, int current, int adj_node);
int				inside_flow(t_path *data, int current, int adj_node);
int				break_flow(t_path *data, int current, int adj_node);

// ALTER FLOW
void			alter_flow(t_path *data);
int				traverse_flow(t_path *data, int node);
int				backtrack_and_delete_flow(t_path *data, int node);

// EVALUATION
typedef struct s_turns
{
	int			total_len;
	int			longest_len;
	int			path_count;
}				t_turns;

int				pathlen(int *paths, int node, int start);
int				get_turn_count(int ants, t_turns *turns);
int				calc_turns(t_path *data, int *paths);
void			get_winner(t_path *data);

// PRINT AND ERROR HANDLING 
void			print_usage(void);
void			check_validity(t_path *data);
void			error(char *error_msg, int exit_code);

// MARCH
typedef struct s_march
{
	char		*moves;
	int			current_link;
	int			ants_marched;
	int			ants_in_end;
	int			buffer;
	int			written;
}				t_march;

void			march_ants(t_path *data, char **input);
void			play_one_turn(t_path *data, t_march *march);
int				curr_neighbors_start(t_path *data, t_hash *current);
int				curr_has_ant(t_hash *current);
char			*stringjoin_free(char *s1, char *s2);
void			initialize_march(t_march *march);
int				start_is_next_to_end(t_path *data);
void			move_all_ants(t_path *data, char **input);
void			add_move(t_march *march, char *ant, char *node);
void			move_from_start(t_path *data, t_hash *curr, t_march *march);
void			move_to_end(t_path *data, t_hash *current, t_march *march);
void			move_to_current(t_path *data, t_hash *current, t_march *march);
int				find_path_len(t_path *data, t_march *march);

#endif