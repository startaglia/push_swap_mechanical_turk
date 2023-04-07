/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:13:27 by startagl          #+#    #+#             */
/*   Updated: 2023/04/07 13:10:55 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	init_moves(t_data *data)
{
	data->moves.pa = 0;
	data->moves.pb = 0;
	data->moves.ra = 0;
	data->moves.rb = 0;
	data->moves.rr = 0;
	data->moves.rra = 0;
	data->moves.rrb = 0;
	data->moves.rrr = 0;
	data->moves.sa = 0;
	data->moves.sb = 0;
}

int	initialize_val(t_data *data, char *av[], int f)
{	
	int	counter;

	counter = get_input_num(av);
	data->a = malloc(counter * sizeof(int));
	data->b = malloc(counter * sizeof(int));
	data->len_a = counter;
	data->len_b = 0;
	data->max_a = 0;
	data->min_a = 0;
	data->max_b = 0;
	data->min_b = 0;
	data->index_string_a = 0;
	data->n_moves = 0;
	data->len_b = 0;
	ft_fill_a(data, av);
	check_double(data);
	init_moves(data);
	ft_ready_to_start(data, f);
	return (0);
}

void	ft_final_half_check(t_data *data)
{
	if (data->index_min_a < data->half_index_a)
	{
		while (data->index_min_a > 0)
		{
			rotate_a(data, 1);
			get_stacks_data(data);
		}
	}
	else
	{
		while (data->index_min_a > 0)
		{
			reverse_rotate_a(data, 1);
			get_stacks_data(data);
		}
	}
}

void	do_the_shit(t_data *data)
{
	if (!check_start_sorted(data))
	{
		push_b(data, 1);
		push_b(data, 1);
		while (3 < data->len_a)
		{
			cicle_a(data);
			ft_sorting(data, 0);
		}
		three_sort(data);
		while (data->len_b > 0)
		{
			cicle_b(data);
			ft_sorting(data, 1);
		}
		ft_final_half_check(data);
	}
}
