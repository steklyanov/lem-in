/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:29:00 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/09 17:13:47 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void	 algo(t_room **room)
{
	int		i;
	int		way;
	t_room  *temp;

	i = 0;
	way = 0;
	temp = (*room)->next;
	while (++i < temp->count_room)// (temp->next)
	{
		temp->blame += 1;
		while (temp->connections->next)
		{
			if(temp->connections->connect == 0)
			{
				temp->connections->connect = 1;
			}
			temp->connections = temp->connections->next;
		}
		way += 1; 
	}
}

void	count_room(t_room **room)
{
	t_room *temp;

	temp = (*room)->next;

	while (temp->blame != 1)
	{
		temp->blame = 1;
		temp->count_room +=1;
		temp = temp->next;
	}
	temp->count_room += 1;
}

// int		count_rooms(char **argv)
// {

// }