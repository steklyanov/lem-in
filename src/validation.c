/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:15:39 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/13 16:32:35 by mmraz            ###   ########.fr       */
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
	return(1);
}

int			get_ants_amount(char *line, t_farm *farm)
{
	return(1);
}


int			get_comment_data(char *line, t_farm *farm)
{
	return(1);
}