/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:55:52 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/20 15:01:37 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

/* takes **argv and turns it into a t_farm, */
/* in case of a error farm->rooms_amount = 0, succes =  1 */
t_farm		*create_farm(t_farm *farm)
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
		free(line);
	}
	operation < 0 ? farm->rooms_amount = 0 :ft_printf("");
	// TODO all necessary frees(t_farm)
	return (farm);
}

/* ENTRY POINT FOR APLICATION */
int		main(int argc, char **argv)
{
	t_farm	*farm;

	farm = allocate_farm_memory();
	create_farm(farm);
	if (farm->rooms_amount == 0)
		ft_printf("Error\n");
	print_farm(farm);
	free_farm(farm);
	return (0);
}
