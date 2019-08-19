/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_fnctns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:00:04 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/19 20:02:23 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

/*Check name, coord and status(start, end). Fill room, or return 0 */
int			validate_room(char *line, t_farm *farm)
{
	char	**elements;
	int		index;

	index = 0;
	elements = ft_strsplitspaces(line);
	if (get_array_len(elements) == 3 && check_name(elements[0], farm))
	{
		farm->room = new_room(elements, farm);
		farm->rooms_amount++;
		index = 1;
	}
	free_str_arr(elements);
	return (index);
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

t_room		*return_room_by_name(t_farm *farm, char *name)
{
	t_room	*tmp;

	tmp = farm->room;
	while (tmp)
	{
		if (tmp->name && ft_strcmp(name, tmp->name) == 0)
			break;
		tmp = tmp->next;
	}
	return (tmp);
}

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
