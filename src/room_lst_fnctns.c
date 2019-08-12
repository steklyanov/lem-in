/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_lst_fnctns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 18:31:24 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/12 14:45:47 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"


int		check_name(char *name, t_farm *farm)
{
	return (1);
}

int		check_coord(int x, int y, t_farm *farm)
{
	return (1);
}

t_room	*new_room(char **argv, t_farm *farm)
{
	t_room	*new;

	if (!(new = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	if (!(new->connections = (t_conn*)malloc(sizeof(t_conn))))
		return (NULL);
	new->name = ft_strnew(ft_strlen(argv[1]));
	new->is_start = 0;
	new->is_finish = 0;
	new->blame = 0;
	new->connections = NULL;
	new->next = farm->room;
	return (new);
}