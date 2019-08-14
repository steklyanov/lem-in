/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edges_fnctns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:03 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/14 19:09:51 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

/* Split str by '-' delimeter, check if name in room list, fill s_conn struct.*/
int			validate_edges(char *line, t_farm *farm)
{
	char	**elements;
	int		index;

	index = 0;
	elements = ft_strsplit(line, '-');
	if (get_array_len(elements) == 2 &&
	check_name(elements[0], farm) == 0 && check_name(elements[1], farm) == 0)
	{
		if (fill_connections(elements[0], elements[1], farm) == 1)
			return(1);
	}
	free_str_arr(elements);
	return (0);
	
}

/* Аills the t_conn structure with a list containing a pointer to the room.*/
int     fill_connections(char *edge_1, char *edge_2, t_farm *farm)
{
	t_room	*tmp1;
	t_room	*tmp2;
	t_conn	*connection1;
	t_conn	*connection2;

	if (farm->room == NULL)
		return (0);
	tmp1 = return_room_by_name(farm, edge_1);
	if (!(connection1 = (t_conn*)malloc(sizeof(t_conn))))
		return (0);
	connection1->next = tmp1->connections;
	tmp2 = return_room_by_name(farm, edge_2);
	if (!(connection2 = (t_conn*)malloc(sizeof(t_conn))))
		return (0);
	connection2->next = tmp2->connections;
	connection1->room = tmp2;
	tmp1->connections = connection1;
	connection2->room = tmp1;
	tmp2->connections = connection2;
	return (1);
}

int		check_coord(int x, int y, t_farm *farm)
{
	return (1);
}