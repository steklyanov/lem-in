/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:15:39 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/13 21:57:25 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

/*Check name, coord and status(start, end). Fill room, or return 0 */
int			validate_room(char *line, t_farm *farm)
{
	ft_printf("VALIDATE ROOM FNCTN\n");
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

int			validate_edges(char *line, t_farm *farm)
{
	ft_printf("VALIDATE EDGES FNCTN\n");
	char	**elements;
	int		index;

	index = 0;
	elements = ft_strsplit(line, '-');
	if (get_array_len(elements) == 2 &&
	check_name(elements[0], farm) == 0 && check_name(elements[1], farm) == 0)
	{
		
		return(1);
	}
		
	return (0);
	
}

/* Just atoi arg, but if necessary can implement check for trash symb */
int			get_ants_amount(char *line, t_farm *farm)
{
	int amount;
	
	amount = ft_atoi(line);
	if (amount)
		farm->ant_amount = amount;
	return(amount);
}

/* In the case of a comment about to start or finish, */
/*  creates a room with a variable, the name remains NULL */
int			get_comment_data(char *line, t_farm *farm)
{
	ft_printf("GET COMMENT DATA\n");
	t_room	*new;

	if (ft_strequ("##start", line))
	{
		new = allocate_room();
		new->is_start = 1;
		new->is_finish = 0;
		new->next = farm->room;
		farm->room = new;
	}
	else if (ft_strequ("##finish", line))
	{
		new = allocate_room();
		new->is_finish = 1;
		new->is_start = 0;
		new->next = farm->room;
		farm->room = new;
	}
	return(1);
}