/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spot_in_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:43:56 by startagl          #+#    #+#             */
/*   Updated: 2023/04/05 15:47:41 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	upper_half(t_data *data, int i)
{
	int	temp_moves;

	temp_moves = 0;
	if (i == data->minor_index_num_b)
		temp_moves = data->minor_index_num_b;
	else if (i < data->minor_index_num_b)
		temp_moves = data->minor_index_num_b;
	else if (i > data->minor_index_num_b)
		temp_moves = i;
	if ((temp_moves < data->tot_moves) || (i == 0))
		upper_half_utils_b(data, i, temp_moves);
}

void	cicle_a(t_data *data)
{
	int	i;

	i = 0;
	data->tot_moves = 0;
	while (i < data->len_a)
	{
		data->minor_index_num_b = find_minor_b(data, i);
		if (data->minor_index_num_b == -1)
			data->minor_index_num_b = find_major_b(data, i);
		find_spot_in_b(data, i);
		i++;
	}
}

void	lower_half(t_data *data, int i)
{
	int	temp_moves;

	temp_moves = 0;
	if ((data->len_a - i) == (data->len_b - data->minor_index_num_b))
		temp_moves = data->len_b - data->minor_index_num_b;
	else if ((data->len_a - i) < (data->len_b - data->minor_index_num_b))
		temp_moves = data->len_b - data->minor_index_num_b;
	else if ((data->len_a - i) > (data->len_b - data->minor_index_num_b))
		temp_moves = data->len_a - i;
	if ((temp_moves < data->tot_moves) || (i == 0))
		lower_half_utils_b(data, i, temp_moves);
}

void	different_half(t_data *data, int i)
{
	int	temp_moves;

	temp_moves = 0;
	if (i < data->half_index_a && data->minor_index_num_b
		>= data->half_index_b)
		temp_moves = i + (data->len_b - data->minor_index_num_b);
	else if (i >= data->half_index_a && data->minor_index_num_b
		< data->half_index_b)
		temp_moves = data->minor_index_num_b + (data->len_a - i);
	if ((temp_moves < data->tot_moves) || (i == 0))
		different_half_utils_b(data, i, temp_moves);
}

int	find_spot_in_b(t_data *data, int i)
{
	get_stacks_data(data);
	if (i < data->half_index_a && data->minor_index_num_b
		< data->half_index_b)
		upper_half(data, i);
	else if (i >= data->half_index_a && data->minor_index_num_b
		>= data->half_index_b)
		lower_half(data, i);
	else
		different_half(data, i);
	get_stacks_data(data);
	return (0);
}
