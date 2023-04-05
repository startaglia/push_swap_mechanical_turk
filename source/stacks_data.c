/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:03:21 by startagl          #+#    #+#             */
/*   Updated: 2023/04/05 15:04:58 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	find_major_b(t_data *data, int i)
{
	int	j;
	int	major_index;

	j = 0;
	major_index = -1;
	while (j < data->len_b)
	{
		if (data->b[j] > data->a[i]
			&& (major_index == -1
				|| data->b[j] > data->b[major_index]))
				major_index = j;
		j++;
	}
	return (major_index);
}

int	find_minor_b(t_data *data, int i)
{
	int	j;
	int	minor_index;

	j = 0;
	minor_index = -1;
	while (j < data->len_b)
	{
		if (data->b[j] < data->a[i]
			&& (minor_index == -1
				|| data->b[j] > data->b[minor_index]))
					minor_index = j;
		j++;
	}
	return (minor_index);
}

int	find_middle_stack(t_data *data, int f)
{
	int	half_index;

	half_index = 0;
	if (f == 1)
	{
		if ((data->len_a) % 2 == 0)
			half_index = ((data->len_a) / 2);
		else if ((data->len_a) % 2 == 1)
			half_index = (((data->len_a) / 2) + 1);
	}
	else
	{
		if ((data->len_b) % 2 == 0)
			half_index = ((data->len_b) / 2);
		else if ((data->len_b) % 2 == 1)
			half_index = (((data->len_b) / 2) + 1);
	}
	return (half_index);
}

void	get_stacks_data(t_data *data)
{
	data->max_a = check_a_max_num(data);
	data->min_a = check_a_min_num(data);
	data->index_max_a = check_a_max_num_index(data);
	data->index_min_a = check_a_min_num_index(data);
	data->max_b = check_b_max_num(data);
	data->min_b = check_b_min_num(data);
	data->index_max_b = check_b_max_num_index(data);
	data->index_min_b = check_b_min_num_index(data);
	data->half_index_a = find_middle_stack(data, 1);
	data->half_index_b = find_middle_stack(data, 0);
}
