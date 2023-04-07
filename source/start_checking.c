/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:20:03 by startagl          #+#    #+#             */
/*   Updated: 2023/04/07 13:00:51 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	get_input_num(char **av)
{
	char	**value_to_split;
	int		j;
	int		i;
	int		counter;

	counter = 0;
	j = 0;
	while (av[++j])
	{
		ft_is_valid_num(av, j);
		i = 0;
		value_to_split = ft_split(av[j], 32);
		while (value_to_split[i])
			i++;
		if (i == 0)
			ft_print_error();
		else if (i == 1)
			counter++;
		else if (i > 1)
			counter += i;
		ft_free_mem(value_to_split, 1);
	}
	return (counter);
}

void	ft_ready_to_start(t_data *data, int f)
{
	if (f == 0)
	{
		if (!(check_a_input_num(data)))
		{
			if (data->len_a == 2 && !check_start_sorted(data))
			{
				swap_a(data, 1);
				exit(0);
			}
			else if (data->len_a == 3 && !check_start_sorted(data))
			{
				three_sort(data);
				exit(0);
			}
			else
				exit(0);
		}
	}
}
