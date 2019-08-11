/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_fnctn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:45:58 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/11 16:47:59 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int     get_array_len(char **array)
{
	int index;

	index = 0;
	while(array[index++])
		;
	return(index);
}

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