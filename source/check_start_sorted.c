/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:23:30 by startagl          #+#    #+#             */
/*   Updated: 2023/04/05 15:04:18 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	check_start_sorted(t_data	*data)
{
	int	i;

	i = 0;
	while (i < data->len_a - 1)
	{
		if (data->a[i] < data->a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
