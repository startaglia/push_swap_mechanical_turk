/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_num_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:46:28 by startagl          #+#    #+#             */
/*   Updated: 2023/04/05 15:04:42 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	check_b_max_num_index(t_data *data)
{
	int	i;
	int	max;
	int	index;

	i = 0;
	index = 0;
	max = data->b[i];
	while (i < data->len_b)
	{
		if (data->b[i] > max)
		{
			max = data->b[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	check_b_max_num(t_data *data)
{
	int	i;
	int	max;

	i = 0;
	max = data->b[i];
	while (i < data->len_b)
	{
		if (data->b[i] > max)
			max = data->b[i];
		i++;
	}
	return (max);
}

int	check_b_min_num_index(t_data *data)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	index = 0;
	min = data->b[i];
	while (i < data->len_b)
	{
		if (data->b[i] < min)
		{
			min = data->b[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	check_b_min_num(t_data *data)
{
	int	i;
	int	min;

	i = 0;
	min = data->b[i];
	while (i < data->len_b)
	{
		if (data->b[i] < min)
			min = data->b[i];
		i++;
	}
	return (min);
}
