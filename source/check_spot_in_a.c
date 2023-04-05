/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spot_in_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:58:18 by startagl          #+#    #+#             */
/*   Updated: 2023/04/05 15:27:21 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	cicle_b(t_data *data)
{
	int	i;

	i = 0;
	data->tot_moves = 0;
	while (i < data->len_b)
	{
		data->minor_index_num_a = find_major_a(data, i);
		if (data->minor_index_num_a == -1)
			data->minor_index_num_a = find_minor_a(data, i);
		find_spot_in_a(data, i);
		i++;
	}
}

void	upper_half_a(t_data *data, int i)
{
	int	temp_moves;

	temp_moves = 0;
	if (i == data->minor_index_num_a)
		temp_moves = data->minor_index_num_a;
	else if (i < data->minor_index_num_a)
		temp_moves = data->minor_index_num_a;
	else if (i > data->minor_index_num_a)
		temp_moves = i;
	if ((temp_moves < data->tot_moves) || (i == 0))
		upper_half_a_utils(data, i, temp_moves);
}

void	lower_half_a(t_data *data, int i)
{
	int	temp_moves;

	temp_moves = 0;
	if ((data->len_b - i) == (data->len_a - data->minor_index_num_a))
		temp_moves = data->len_a - data->minor_index_num_a;
	else if ((data->len_b - i) < (data->len_a - data->minor_index_num_a))
		temp_moves = data->len_a - data->minor_index_num_a;
	else if ((data->len_b - i) > (data->len_a - data->minor_index_num_a))
		temp_moves = data->len_b - i;
	if ((temp_moves < data->tot_moves) || (i == 0))
		lower_half_a_utils(data, i, temp_moves);
}

void	different_half_a(t_data *data, int i)
{
	int	temp_moves;

	temp_moves = 0;
	if (i < data->half_index_b && data->minor_index_num_a
		>= data->half_index_a)
		temp_moves = i + (data->len_a - data->minor_index_num_a);
	else if (i >= data->half_index_b && data->minor_index_num_a
		< data->half_index_a)
		temp_moves = data->minor_index_num_a + (data->len_b - i);
	if ((temp_moves < data->tot_moves) || (i == 0))
		different_half_a_utils(data, i, temp_moves);
}

int	find_spot_in_a(t_data *data, int i)
{
	get_stacks_data(data);
	if (i < data->half_index_b && data->minor_index_num_a
		< data->half_index_a)
		upper_half_a(data, i);
	else if (i >= data->half_index_b && data->minor_index_num_a
		>= data->half_index_a)
		lower_half_a(data, i);
	else
		different_half_a(data, i);
	get_stacks_data(data);
	return (0);
}
