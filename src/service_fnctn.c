/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_fnctn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:45:58 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/12 14:44:09 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

/* Return len of NULL terminated array of chars. */
int     get_array_len(char **array)
{
	int index;

	index = 0;
	while(array[index++])
		;
	return(index);
}

/* Free NULL terminated array of chars. */
void	free_str_arr(char **array)
{
	int	index;

	index = 0;
	while(array[index])
	{
		free(array[index]);
		index++;
	}
}

/* Allocate memory for farm structure. */
t_farm	*allocate_farm_memory()
{
	t_farm	*farm;

	if (!(farm = (t_farm*)malloc(sizeof(t_farm))))
		return (NULL);
	farm->rooms_amount = 0;
	farm->ant_amount = 0;
	// if (!(farm->room = (t_room*)malloc(sizeof(t_room))))
	// 	return (NULL);
	farm->room = NULL;
	return (farm);
}

void	print_farm(t_farm *farm)
{
	ft_printf("%d", farm->ant_amount);
}