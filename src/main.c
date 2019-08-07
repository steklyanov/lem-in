/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:55:52 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/07 14:32:16 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int		main(int argc, char **argv)
{
	long long	*stack;

	if (argc > 1)
	{
		stack = init_long_arr();
		stack[0] = 12;
		print_long_int(stack[0]);
		stack[0] = set_bit(stack[0], ft_atoi(argv[1]));
		print_long_int(stack[0]);
		// example how to set bit in room 200
		stack[0] = set_bit(stack[ft_div_64(30)], ft_mod_64(30));
		print_long_int(stack[0]);
		free(stack);
	}
	return (0);
}
