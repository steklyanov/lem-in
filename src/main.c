/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:55:52 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/11 14:46:55 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"


void		validate_rooms()
{

}

int			get_operation_numbr(char *line, int operation)
{

}

/* takes **argv and turns it into a t_farm, */
/* in case of a error return 0, succes 1 */
t_farm		*create_farm(char **argv, t_farm *farm)
{
	char	*line;
	int		operation;

	operation = 0;
	while(get_next_line(0, &line) > 0)
	{
		operation = get_operation_nmbr(line, operation);
		if (operation == 1)
			validate_room(line, farm);
		else if (operation == 2)
			validate_edges(line, farm);
		else if (operation == 0)
			get_ants_amount(line);
		else
			break;
	}
	operation < 0 ? farm->rooms_amount = 0 :ft_printf("");
	// TODO all necessary frees, t_farm, line
	return (farm);
}

int		main(int argc, char **argv)
{
	t_farm	*farm;
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
