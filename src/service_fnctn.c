/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_fnctn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:45:58 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/20 14:53:55 by mmraz            ###   ########.fr       */
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
	free(array);
}

/* Print all rooms in list and all connections with other rooms */
void	print_farm(t_farm *farm)
{
	t_room	*tmp;
	t_conn	*tmp_conn;

	ft_printf("ant_amount = %d\n", farm->ant_amount);
	ft_printf("rooms amount = %d\n", farm->rooms_amount);
	tmp = farm->room;
	while(tmp)
	{
		ft_printf("________________________\n");
		ft_printf("name = %s\n", tmp->name);
		ft_printf("is_start = %d\n", tmp->is_start);
		ft_printf("is_finish = %d\n", tmp->is_finish);
		ft_printf("blame = %d\n", tmp->blame);
		ft_printf("\n");
		if (tmp->connections)
		{
			tmp_conn = tmp->connections;
			ft_printf("| connect to rooms: |\n");
			while(tmp_conn)
			{
				ft_printf("%s ", tmp_conn->room->name);
				tmp_conn = tmp_conn->next;
			}
			ft_printf("\n");
		}
		tmp = tmp->next;
	}
}


void	free_farm(t_farm *farm)
{
	// void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
	if (!farm)
		return ;
	free_room(farm->room);
	free(farm);
}

void	free_room(t_room *room)
{
	if (!room)
		return ;
	free_room(room->next);
	free_connections(room->connections);
	free(room->name);
	// free(room->next);
	free(room);
}

void	free_connections(t_conn *connect)
{
	if (!connect)
		return ;
	free_connections(connect->next);
	free(connect);
}