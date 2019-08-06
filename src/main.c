/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:55:52 by mmraz             #+#    #+#             */
/*   Updated: 2019/08/06 16:43:23 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int		main(int argc, char **argv)
{
	ft_printf("%s\n", argv[0]);
	if (argc > 1)
	{
		ft_printf("mod = %d",ft_mod_64(ft_atoi(argv[1])));
		ft_printf("div = %d",ft_div_64(ft_atoi(argv[1])));
	}
	return (0);
}

