/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:34:10 by startagl          #+#    #+#             */
/*   Updated: 2023/04/05 15:03:20 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	reverse_rotate_a(t_data *data, int f)
{
	int	i;
	int	temp;

	i = data->len_a - 1;
	temp = 0;
	while (i > 0)
	{
		temp = data->a[i - 1];
		data->a[i - 1] = data->a[i];
		data->a[i] = temp;
		i --;
	}
	if (f == 1)
		ft_printf("rra\n");
	data->n_moves++;
	get_stacks_data(data);
}

void	reverse_rotate_b(t_data *data, int f)
{
	int	i;
	int	temp;

	i = data->len_b - 1;
	temp = 0;
	while (i > 0)
	{
		temp = data->b[i - 1];
		data->b[i - 1] = data->b[i];
		data->b[i] = temp;
		i --;
	}
	if (f == 1)
		ft_printf("rrb\n");
	data->n_moves++;
	get_stacks_data(data);
}

void	reverse_rotate_rrr(t_data *data, int f)
{
	reverse_rotate_a(data, 0);
	reverse_rotate_b(data, 0);
	if (f == 1)
		ft_printf("rrr\n");
	data->n_moves--;
	get_stacks_data(data);
}
