/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 19:27:08 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/22 18:29:31 by mmraz            ###   ########.fr       */
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
	int			iteration;

	iteration = 1;
	solution = allocate_solution(solution_amount_counter(farm->room));
	start = find_start(farm->room);
	// print_farm(farm);
	find_quickest_way(start, solution, iteration);
}

/* recursively traverses all paths and finds the shortest path to the finish */
int    find_quickest_way(t_room *room, t_solution *solution, int iter)
{
	t_conn  *tmp;

	solution->power_of_sol[iter - 1] = 0;
	if (room && room->connections && room->connections->room != NULL)
		tmp = room->connections;
	else
		return (0);
	if (room->is_finish == 1)
		return (1);
	if (room->blame == 0)
		room->blame = iter;
	else
		return (0);
	while(tmp)
	{
		if (find_quickest_way(tmp->room, solution, iter) == 1)
		{
			new_solution(tmp, solution, iter);
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

void	new_solution(t_conn *connections, t_solution *solution, int iter)
{
	t_conn	*new;

	new = connections;
	solution->power_of_sol[iter - 1]++;
	new->next = solution->solutions_arr[iter - 1];
	solution->solutions_arr[iter - 1] = new;
	print_solution(solution);
	// get_biggest_diff(solution);
}