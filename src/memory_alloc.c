/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:58:10 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/22 18:28:18 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

/* Allocate memory for farm structure. */
t_farm	*allocate_farm_memory()
{
	t_farm	*farm;

	if (!(farm = (t_farm*)malloc(sizeof(t_farm))))
		return (NULL);
	farm->rooms_amount = 0;
	farm->ant_amount = 0;
	farm->room = NULL;
	return (farm);
}

/*  Allocate memory for t_room structure. */
t_room	*allocate_room()
{
	t_room	*new;

	if (!(new = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	// if (!(new->connections = (t_conn*)malloc(sizeof(t_conn))))
	// 	return (NULL);
	ft_bzero(new, sizeof(t_room));
	return (new);
}

t_conn	*allocate_connection()
{
	t_conn	*new;

	// if (!(new = (t_conn*)malloc(sizeof(t_conn))))
	// 	return (NULL);
	new->room = NULL;
	new->next = NULL;
	return (new);
}

t_antstream		*allocate_antstream()
{
	t_antstream	*new;

	if (!(new = (t_antstream*)malloc(sizeof(t_antstream))))
		return (NULL);
	if (!(new->solution = (t_conn*)malloc(sizeof(t_conn))))
		return (NULL);
	new->next = NULL;
	new->number = 0;

	return (new);
}

t_solution		*allocate_solution(int sol_amount)
{
	t_solution	*new;
	int			index;

	index = 0;
	if (!(new = (t_solution*)malloc(sizeof(t_solution))))
		return (NULL);
	if (!(new->solutions_arr = (t_conn**)malloc(sizeof(t_conn) * sol_amount)))
		return (NULL);
	while(index < sol_amount)
	{
		new->solutions_arr[index] = NULL;
		index++;
	}
	if (!(new->power_of_sol = (int *)malloc(sizeof(int) * sol_amount)))
		return (NULL);
	new->solution_amount = sol_amount;
	return (new);
}