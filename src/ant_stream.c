/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_stream.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:16:45 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/19 16:22:40 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

/* Function determines the length of the longest path and fills the structure */
/*  with its number and length, removing it from the array of options */
void		get_biggest_diff(t_solution *solution)
{
	int	index;
	int	counter;

	index = 0;
	while (index < solution->solution_amount)
	{
		if (solution->power_of_sol[index] > solution->biggest_diff)
		{
			solution->biggest_diff = solution->power_of_sol[index];
			counter = index;
		}
		index++;
	}
	solution->biggest_way = counter;
	solution->power_of_sol[counter] = 0;
}


void    stream_ants(t_farm *farm, t_solution *solution)
{
	t_antstream *antstream;
	int	index;

	antstream = NULL;
	index = 0;
	get_biggest_diff(solution);
	while(index < solution->solution_amount &&
	farm->ant_amount > solution->biggest_diff)
	{
		if (antstream)
			move_ants(antstream);
		new_ant(solution->solutions_arr[index], antstream);
	}
	print_step(antstream);
}

void	move_ants(t_antstream *antstream)
{
	while(antstream != NULL)
	{
		antstream->room_number++;
		antstream = antstream->next;
	}
}

void	new_ant(t_conn *solution, t_antstream *antstream)
{
	t_antstream *new;

	new = allocate_antstream();
	if (antstream)
		new->number = antstream->number + 1;
	else
		new->number = 0;
	new->solution = solution;
	new->room_number = 0;
	new->next = antstream;
	antstream = new;
}

void	print_ant(t_antstream *antstream)
{
	while(antstream != NULL)
	{
		ft_printf("L%d-%s", antstream->number,
		return_room_name_by_nmbr(antstream->solution, antstream->room_number));
		antstream->room_number++;
		antstream = antstream->next;
	}
}

char	*return_room_name_by_nmbr(t_conn *list, int nmbr)
{
	while(nmbr-- && list)
		list = list->next;
	return (list->room->name);
}