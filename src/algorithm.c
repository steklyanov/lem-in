/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:29:00 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/06 17:54:20 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int     ft_mod_64(int numb)
{
    int position;

    position = 0;
    if (numb >= 64)
    {
        position = numb - (64 * (int)(numb / 64));
        ft_printf("  %d   ", position); 
    }
    else
        return (numb);
    return (position);
}

int     ft_div_64(int numb)
{
    return ((int)(numb / 64));
}

int     room_status(long long *rooms, int room_nbr)
{
    if ((rooms[ft_div_64(room_nbr)] & (1 << ft_mod_64(room_nbr))) == 0)
        return (0);
    return (1);
}