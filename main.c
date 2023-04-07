/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:11:46 by startagl          #+#    #+#             */
/*   Updated: 2023/04/07 12:56:34 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;
	int		j;

	j = 1;
	if (ac > 1)
	{
		data = malloc(sizeof(t_data));
		initialize_val(data, av, 0);
		do_the_shit(data);
		ft_free_data(data);
	}
	return (0);
}
