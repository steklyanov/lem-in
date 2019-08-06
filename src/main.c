/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:55:52 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/06 17:52:33 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int		main(int argc, char **argv)
{
	long long	*stack;

	ft_printf("%s\n", argv[0]);
	if (argc > 1)
	{
		stack = init_long_arr();
		stack[0] = 12;
		print_long_int(stack[0]);
		// ft_printf("mod = %d",ft_mod_64(stack[0]));
		// ft_printf("div = %d",ft_div_64(stack[0]));
		ft_printf(" %d ", room_status(stack, ft_atoi(argv[1])));
	}
	return (0);
}

