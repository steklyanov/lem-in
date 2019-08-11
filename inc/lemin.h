/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:55:54 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/11 14:39:42 by mmraz            ###   ########.fr       */
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

/* structure for writing graph edges  */
typedef struct      s_conn
{
	t_room          *room;
	struct s_conn	*next;
}                   t_conn;

/* main room structure  */
struct      s_room
{
	char    *name;
	int     is_start;
	int     is_finish;
	int     blame;
	int     res_3;
	int     res_4;
    t_conn  *connections;
};

/* main graph structure */
struct      s_farm
{
	t_room  room;
    int     rooms_amount;
    int     aunt_amount;
	t_farm  *next;
};

t_farm		*create_farm(char **argv, t_farm *farm);

#endif