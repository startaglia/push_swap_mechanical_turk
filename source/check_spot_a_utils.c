/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spot_a_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:18:57 by startagl          #+#    #+#             */
/*   Updated: 2023/04/05 15:26:56 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	upper_half_a_utils(t_data *data, int i, int temp_moves)
{
	init_moves(data);
	data->tot_moves = temp_moves;
	data->index_b_at_push = i;
	data->index_a_at_push = data->minor_index_num_a;
	if (i == data->minor_index_num_a)
		data->moves.rr = data->minor_index_num_a;
	else if (i < data->minor_index_num_a)
	{
		data->moves.rr = i;
		data->moves.ra = data->minor_index_num_a - i;
	}
	else if (i > data->minor_index_num_a)
	{
		data->moves.rr = data->minor_index_num_a;
		data->moves.rb = i - data->minor_index_num_a;
	}
}

void	lower_half_a_utils(t_data *data, int i, int temp_moves)
{
	init_moves(data);
	data->tot_moves = temp_moves;
	data->index_a_at_push = data->minor_index_num_a;
	data->index_b_at_push = i;
	if ((data->len_b - i) == (data->len_a - data->minor_index_num_a))
		data->moves.rrr = data->len_a - data->minor_index_num_a;
	else if ((data->len_b - i) < (data->len_a - data->minor_index_num_a))
	{
		data->moves.rrr = data->len_b - i;
		data->moves.rra = (data->len_a - data->minor_index_num_a)
			- (data->len_b - i);
	}
	else if ((data->len_b - i) > (data->len_a - data->minor_index_num_a))
	{
		data->moves.rrr = data->len_a - data->minor_index_num_a;
		data->moves.rrb = (data->len_b - i)
			- (data->len_a - data->minor_index_num_a);
	}
}

void	different_half_a_utils(t_data *data, int i, int temp_moves)
{
	init_moves(data);
	data->tot_moves = temp_moves;
	data->index_a_at_push = data->minor_index_num_a;
	data->index_b_at_push = i;
	if (i < data->half_index_b && data->minor_index_num_a
		>= data->half_index_a)
	{
		data->moves.rb = i;
		data->moves.rra = data->len_a - data->minor_index_num_a;
	}
	else if (i > data->half_index_b && data->minor_index_num_a
		< data->half_index_a)
	{
		data->moves.rrb = data->len_b - i;
		data->moves.ra = i - data->minor_index_num_a ;
	}
}

int	find_major_a(t_data *data, int i)
{
	int	j;
	int	major_index;

	j = 0;
	major_index = -1;
	while (j < data->len_a)
	{
		if (data->a[j] > data->b[i]
			&& (major_index == -1
				|| data->a[j] < data->a[major_index]))
				major_index = j;
		j++;
	}
	return (major_index);
}

int	find_minor_a(t_data *data, int i)
{
	int	j;
	int	minor_index;

	j = 0;
	minor_index = -1;
	while (j < data->len_a)
	{
		if (data->a[j] < data->b[i]
			&& (minor_index == -1
				|| data->a[j] < data->a[minor_index]))
				minor_index = j;
		j++;
	}
	return (minor_index);
}
