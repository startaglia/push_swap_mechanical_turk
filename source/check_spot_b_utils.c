/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spot_b_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:37:01 by startagl          #+#    #+#             */
/*   Updated: 2023/04/05 15:43:26 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	upper_half_utils_b(t_data *data, int i, int temp_moves)
{
	init_moves(data);
	data->tot_moves = temp_moves;
	data->index_a_at_push = i;
	data->index_b_at_push = data->minor_index_num_b;
	if (i == data->minor_index_num_b)
		data->moves.rr = data->minor_index_num_b;
	else if (i < data->minor_index_num_b)
	{
		data->moves.rr = i;
		data->moves.rb = data->minor_index_num_b - i;
	}
	else if (i > data->minor_index_num_b)
	{
		data->moves.rr = data->minor_index_num_b;
		data->moves.ra = i - data->minor_index_num_b ;
	}
}

void	lower_half_utils_b(t_data *data, int i, int temp_moves)
{
	init_moves(data);
	data->tot_moves = temp_moves;
	data->index_b_at_push = data->minor_index_num_b;
	data->index_a_at_push = i;
	if ((data->len_a - i) == (data->len_b - data->minor_index_num_b))
		data->moves.rrr = data->len_b - data->minor_index_num_b;
	else if ((data->len_a - i) < (data->len_b - data->minor_index_num_b))
	{
		data->moves.rrr = data->len_a - i;
		data->moves.rrb = (data->len_b - data->minor_index_num_b)
			- (data->len_a - i);
	}
	else if ((data->len_a - i) > (data->len_b - data->minor_index_num_b))
	{
		data->moves.rrr = data->len_b - data->minor_index_num_b;
		data->moves.rra = (data->len_a - i)
			- (data->len_b - data->minor_index_num_b);
	}
}

void	different_half_utils_b(t_data *data, int i, int temp_moves)
{
	init_moves(data);
	data->tot_moves = temp_moves;
	data->index_b_at_push = data->minor_index_num_b;
	data->index_a_at_push = i;
	if (i < data->half_index_a && data->minor_index_num_b
		>= data->half_index_b)
	{
		data->moves.ra = i;
		data->moves.rrb = data->len_b - data->minor_index_num_b;
	}
	else if (i >= data->half_index_a && data->minor_index_num_b
		< data->half_index_b)
	{
		data->moves.rb = data->minor_index_num_b;
		data->moves.rra = data->len_a - i;
	}
}
