/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:55:54 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/19 19:21:02 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_farm	t_farm;
typedef struct s_room	t_room;

/* structure for writing graph edges(list)  */
typedef struct	s_conn
{
	t_room          *room;
	int				connect;
	int				number_room;
	struct s_conn	*next;
}				t_conn;

/* main room structure(list)  */
struct      	s_room
{
	char    *name;
	int     is_start;
	int     is_finish;
	int     blame;
    t_conn  *connections;
	t_room	*next;
};

/* main graph structure */
struct      	s_farm
{
	t_room  *room;
    int     rooms_amount;
    int     ant_amount;
};

/* structure for sending ants according to decision */
typedef struct	s_solution
{
	int		solution_amount;
	int		biggest_diff;
	int		biggest_way;
	t_conn	**solutions_arr;
	int		*power_of_sol;
}				t_solution;

/* collect data about current ant position */
typedef struct			s_antstream
{
	int					number;
	int					room_number;
	t_conn				*solution;
	struct s_antstream	*next;
}						t_antstream;

/* service functions */
int			get_array_len(char **array);
void		free_str_arr(char **array);
void		print_farm(t_farm *farm);

/* validation, memory allocation, farm filling */
t_farm		*create_farm(t_farm *farm);
int			main_validation_fnctn(char *line, t_farm *farm, int operation);
int			get_operation_nmbr(char *line, int op);
int			validate_room(char *line, t_farm *farm);
int			validate_edges(char *line, t_farm *farm);
int			get_ants_amount(char *line, t_farm *farm);
int			get_comment_data(char *line, t_farm *farm);
int			fill_connections(char *edge_1, char *edge_2, t_farm *farm);

/* list operations */
int			check_name(char *name, t_farm *farm);
int			check_coord(int x, int y, t_farm *farm);
t_room		*new_room(char **argv, t_farm *farm);
t_room		*allocate_room();
t_conn		*allocate_connection();
t_farm		*allocate_farm_memory();
t_antstream	*allocate_antstream();
t_room		*return_room_by_name(t_farm *farm, char *name);

/* ants streaming */
void		stream_ants(t_farm *farm, t_solution *solution);
void		get_biggest_diff(t_solution *solution);
void		move_ants(t_antstream *antstream);
void		new_ant(t_conn *solution, t_antstream *antstream);
void		print_ant(t_antstream *antstream);
char		*return_room_name_by_nmbr(t_conn *list, int nmbr);

#endif
