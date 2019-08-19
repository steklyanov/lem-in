/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:58:10 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/19 16:10:07 by mmraz            ###   ########.fr       */
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
	if (!(new->connections = (t_conn*)malloc(sizeof(t_conn))))
		return (NULL);
	return (new);
}

t_conn	*allocate_connection()
{
	t_conn	*new;

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
}