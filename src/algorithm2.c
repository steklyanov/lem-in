/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 19:27:08 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/22 15:06:35 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

t_room  *find_start(t_room *room)
{
	ft_printf("find start\n");
	while(room)
	{
		if (room->is_start == 1)
			return (room);
		room = room->next;
	}
	return (NULL);
}

void    main_solution_fnctn(t_farm *farm)
{
	t_solution	*solution;
	t_room      *start;

	solution = allocate_solution(solution_amount_counter(farm->room));
	start = find_start(farm->room);
	// print_farm(farm);
	find_quickest_way(start, solution);
}

/* recursively traverses all paths and finds the shortest path to the finish */
int    find_quickest_way(t_room *room, t_solution *solution)
{
	ft_printf("FIND QUCKEST WAY\n");
	t_conn  *tmp;

	if (room && room->connections && room->connections->room != NULL)
	{
		ft_printf("here1\n");
		tmp = room->connections;
	}
	else
	{
		ft_printf("here\n");
		return (0);
	}
	ft_printf("%s\n", tmp->room->name);
	if (room->is_finish == 1)
		return (1);
	if (room->blame == 0)
		room->blame = 1;
	else
		return (0);
	while(tmp)
	{
		ft_printf("Inside while\n");
		if (find_quickest_way(tmp->room, solution) == 1)
		{
			new_solution(tmp, solution);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

/* counts the minimum number of connections between start and finish */
int     solution_amount_counter(t_room *room)
{
	int start;
	int finish;

	start = 0;
	finish = 0;
	while(room && (start == 0 || finish == 0))
	{
		if (room->is_start != 0)
			start = room->is_start;
		if (room->is_finish != 0)
			finish = room->is_finish;
		room = room->next;
	}
	if (start < finish)
		return (start);
	return(finish);
}

void	new_solution(t_conn *connections, t_solution *solution)
{
	ft_printf("req release\n");
	ft_printf("%s\n", connections->room->name);
}