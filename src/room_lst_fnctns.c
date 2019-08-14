/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_lst_fnctns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 18:31:24 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/14 17:39:52 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

/*  Checking room name for unique value. */
int		check_name(char *name, t_farm *farm)
{
	t_room	*tmp;

	if (farm->room == NULL)
		return (1);
	tmp = farm->room;
	while (tmp)
	{
		if (tmp->name && ft_strcmp(name, tmp->name) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}


t_conn	*allocate_connection()
{
	t_conn	*new;

	new->room = NULL;
	new->next = NULL;
	return (new);
}

int		check_coord(int x, int y, t_farm *farm)
{
	return (1);
}

/*  Allocate memory for t_room structure. */
t_room	*allocate_room()
{
	t_room	*new;

	if (!(new = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	if (!(new->connections = (t_conn*)malloc(sizeof(t_conn))))
		return (NULL);
	return (new);
}

/* Сreates a new room, fills the name. In case there is an unnamed room */
/*  with a start or finish mark, it simply fills in the values. */
t_room	*new_room(char **argv, t_farm *farm)
{
	t_room	*new;

	if (farm->room != NULL &&
	((farm->room->is_start == 1 || farm->room->is_finish == 1)
	&& farm->room->name == NULL))
	{
		farm->room->blame = 0;
		farm->room->name = ft_strdup(argv[0]);
		farm->room->connections = NULL;
		return (farm->room);
	}
	if (!(new = allocate_room()))
		return (NULL);
	new->next = farm->room;
	new->blame = 0;
	new->name = ft_strdup(argv[0]);
	new->connections = NULL;
	new->is_start = 0;
	new->is_finish = 0;
	return (new);
}


int     fill_connections(char *edge_1, char *edge_2, t_farm *farm)
{
	ft_printf("FILL connection FNCTN\n");
	t_room	*tmp1;
	t_room	*tmp2;
	t_conn	*connection1;
	t_conn	*connection2;

	if (farm->room == NULL)
		return (1);
	tmp1 = farm->room;
	tmp2 = farm->room;
	while (tmp1)
	{
		if (tmp1->name && ft_strcmp(edge_1, tmp1->name) == 0)
			break;
		tmp1 = tmp1->next;
	}
	while (tmp2)
	{
		if (tmp2->name && ft_strcmp(edge_2, tmp2->name) == 0)
			break;
		tmp2 = tmp2->next;
	}
	ft_printf("edge1 = %s\n", edge_1);
	ft_printf("edge2 = %s\n", edge_2);
	if (!(connection1 = (t_conn*)malloc(sizeof(t_conn))))
		return (0);
	if (!(connection2 = (t_conn*)malloc(sizeof(t_conn))))
		return (0);
	connection1->next = tmp1->connections;
	connection1->room = tmp2;
	tmp1->connections = connection1;


	connection2->next = tmp2->connections;
	connection2->room = tmp1;
	tmp2->connections = connection2;

	return (1);
}