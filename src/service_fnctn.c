/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_fnctn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:45:58 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/07 14:21:24 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void    print_long_int(long long num)
{
    int i;

    i= (sizeof(long long) * 8);
    ft_printf("len = %d\n", i);
    while(i>= 0)
    {
        char c = (num &(1LL<<i))? '1' : '0';
        ft_putchar(c);
        i--;
    }
    ft_printf("\n");
}

/* use for initialize array of rooms status */
long long   *init_long_arr()
{
    long long *arr;

    if (!(arr = (long long*)malloc(sizeof(long long) * 7)))
        return (NULL);
    return (arr);
}