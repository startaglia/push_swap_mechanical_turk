/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:30:51 by startagl          #+#    #+#             */
/*   Updated: 2023/04/05 15:30:24 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	rotate_a(t_data *data, int f)
{
	int	i;
	int	temp;
	int	len;

	i = 0;
	temp = 0;
	len = data->len_a - 1;
	while (i < len)
	{
		temp = data->a[i + 1];
		data->a[i + 1] = data->a[i];
		data->a[i] = temp;
		i ++;
	}
	if (f == 1)
		ft_printf("ra\n");
	data->n_moves++;
	get_stacks_data(data);
}

void	rotate_b(t_data *data, int f)
{
	int	i;
	int	temp;
	int	len;

	i = 0;
	temp = 0;
	len = data->len_b - 1;
	while (i < len)
	{
		temp = data->b[i + 1];
		data->b[i + 1] = data->b[i];
		data->b[i] = temp;
		i ++;
	}
	if (f == 1)
		ft_printf("rb\n");
	data->n_moves++;
	get_stacks_data(data);
}

void	rotate_rr(t_data *data, int f)
{
	rotate_a(data, 0);
	rotate_b(data, 0);
	if (f == 1)
		ft_printf("rr\n");
	data->n_moves--;
	get_stacks_data(data);
}
// void	rotate_b(t_data *data, int f)
// {
// 	int	i;
// 	int	temp;

// 	i = data->len_b - 1;
// 	temp = 0;
// 	while (i > 0)
// 	{
// 		temp = data->b[i - 1];
// 		data->b[i - 1] = data->b[i];
// 		data->b[i] = temp;
// 		i --;
// 	}
// 	if (f == 1)
// 		ft_printf("rrb\n");
// }
