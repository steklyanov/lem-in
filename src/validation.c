/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:15:39 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/22 13:36:51 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

/* Return type of str: room(1), edge(2), comment(3), ant amount(0), error(-1).*/
/* Also check for right order of commands, forbidden "L" symbol. */
int			get_operation_nmbr(char *line, int op)
{
	if (line[0] == 'L')
		return (-1);
	else if (op == -1)
		return (0);
	else if (line[0] == '#')
		return (3);
	else if (ft_strchr(line, '-') != NULL && (op != -1))
		return (2);
	else if (op == 0 || op == 1 || op == 3)
		return (1);
	else
		return (-1);
}

/* Type of operation: edge(2), comment(3), room(1) or ant amount(-1) */
int		main_validation_fnctn(char *line, t_farm *farm, int operation)
{
	int	result;

	if (operation == 1)
		result = validate_room(line, farm);
	else if (operation == 2)
		result = validate_edges(line, farm);
	else if (operation == 0)
		result = get_ants_amount(line, farm);
	else if (operation == 3)
		result = get_comment_data(line, farm);
	else
		return (operation);
	return (result);
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
	t_room	*new;
	t_room	*tmp;

	if (ft_strequ("#start", line))
	{
		ft_printf("IN START FNCTN\n");
		new = allocate_room();
		new->is_start = 1;
		new->next = farm->room;
		farm->room = new;
	}
	else if (ft_strequ("#end", line))
	{
		new = allocate_room();
		new->is_finish = 1;
		new->next = farm->room;
		farm->room = new;
	}
	return(1);
}