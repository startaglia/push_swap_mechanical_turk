/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:45:00 by startagl          #+#    #+#             */
/*   Updated: 2023/04/05 15:00:20 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	push_b(t_data *data, int f)
{
	int	i;

	i = data->len_b;
	while (i > 0)
	{
		data->b[i] = data->b[i - 1];
		i--;
	}
	data->len_b++;
	data->b[0] = data->a[0];
	while (i < data->len_a)
	{
		data->a[i] = data->a[i + 1];
		i++;
	}
	data->len_a--;
	if (f == 1)
		ft_printf("pb\n");
	data->n_moves++;
	get_stacks_data(data);
}

void	push_a(t_data *data, int f)
{
	int	i;

	i = data->len_a;
	while (i > 0)
	{
		data->a[i] = data->a[i - 1];
		i--;
	}
	data->len_a++;
	data->a[0] = data->b[0];
	while (i < data->len_b)
	{
		data->b[i] = data->b[i + 1];
		i++;
	}
	data->len_b--;
	if (f == 1)
		ft_printf("pa\n");
	data->n_moves++;
	get_stacks_data(data);
}
