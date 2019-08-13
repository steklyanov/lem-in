/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_fnctn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:45:58 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/13 19:28:19 by mmraz            ###   ########.fr       */
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
	return(index - 1);
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
	farm->room = NULL;
	return (farm);
}

/* Print all rooms in list and all connections with other rooms */
void	print_farm(t_farm *farm)
{
	t_room	*tmp;

	ft_printf("ant_amount = %d\n", farm->ant_amount);
	ft_printf("rooms amount = %d\n", farm->rooms_amount);
	tmp = farm->room;
	while(tmp)
	{
		ft_printf("name = %s\n", tmp->name);
		ft_printf("is_start = %d\n", tmp->is_start);
		ft_printf("is_finish = %d\n", tmp->is_finish);
		ft_printf("blame = %d\n", tmp->blame);
		ft_printf("\n");
		tmp = tmp->next;
	}
}