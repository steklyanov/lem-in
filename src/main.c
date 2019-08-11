/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:55:52 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/11 18:23:48 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

/* Return type of str: room(1), edge(2), comment(3), ant amount(0), error(-1).*/
/* Also check for right order of commands, forbidden "L" symbol. */
int			get_operation_numbr(char *line, int op)
{
	if (line[0] = "L")
		return (-1);
	else if (op == -1)
		return (0);
	else if (line[0] == '#')
		return (3);
	else if (ft_strchr("-", line) > 0 && (op != -1))
		return (2);
	if (op == 0 || op == 1)
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
		result =validate_edges(line, farm);
	else if (operation == 0)
		result = get_ants_amount(line, farm);
	else if (operation = 3)
		result = get_comment_data(line, farm);
	else
		return (operation);
	return (result);
}

/* takes **argv and turns it into a t_farm, */
/* in case of a error farm->rooms_amount = 0, succes =  1 */
t_farm		*create_farm(char **argv, t_farm *farm)
{
	char	*line;
	int		operation;

	operation = -1;
	while(get_next_line(0, &line) > 0)
	{
		operation = get_operation_nmbr(line, operation);
		if (!main_validation_fnctn(line, farm, operation))
		{
			operation = -1;
			break;
		}
	}
	operation < 0 ? farm->rooms_amount = 0 :ft_printf("");
	// TODO all necessary frees, t_farm, line
	return (farm);
}

/* ENTRY POINT FOR APLICATION */
int		main(int argc, char **argv)
{
	t_farm	*farm;

	farm = allocate_farm();
	if (argc > 1)
	{
		farm = create_farm(argv, farm);
		if (farm->rooms_amount > 0)
			print_farm(farm);
	}
	else
		ft_printf("Fu**ing usage");
	return (0);
}
