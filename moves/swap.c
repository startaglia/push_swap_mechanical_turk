/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:29:02 by startagl          #+#    #+#             */
/*   Updated: 2023/04/05 15:30:48 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	swap_a(t_data *data, int f)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	if (data->len_a == 1)
		return ;
	temp = data->a[1];
	data->a[1] = data->a[0];
	data->a[0] = temp;
	if (f == 1)
		ft_printf("sa\n");
	data->n_moves++;
	get_stacks_data(data);
}

void	swap_b(t_data *data, int f)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	if (data->len_b == 1)
		return ;
	temp = data->b[1];
	data->b[1] = data->b[0];
	data->b[0] = temp;
	if (f == 1)
		ft_printf("sb\n");
	data->n_moves++;
	get_stacks_data(data);
}

void	swap_ss(t_data *data, int f)
{
	swap_a(data, 0);
	swap_b(data, 0);
	if (f == 1)
		ft_printf("ss\n");
	data->n_moves--;
	get_stacks_data(data);
}
