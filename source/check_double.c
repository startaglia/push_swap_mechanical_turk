/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:02:30 by startagl          #+#    #+#             */
/*   Updated: 2023/04/05 15:10:41 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	*copy_stack(t_data *data)
{
	int		i;
	int		j;
	int		*res;

	res = malloc(data->len_a * sizeof(int));
	i = 0;
	j = 0;
	while (i < data->len_a)
	{
		res[j] = data->a[i];
		i++;
		j++;
	}
	return (res);
}

int	check_double(t_data *data)
{
	int		i;
	int		j;
	int		*temp_stack;

	i = 0;
	temp_stack = copy_stack(data);
	while (i < data->len_a)
	{
		j = 0;
		while (j < data->len_a)
		{
			if (i != j && data->a[j] == temp_stack[i])
				ft_print_error();
			j++;
		}
		i++;
	}
	free(temp_stack);
	return (0);
}

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_sorting(t_data *data, int f)
{
	while (data->moves.pa-- > 0)
		push_a(data, 1);
	while (data->moves.pb-- > 0)
		push_b(data, 1);
	while (data->moves.ra-- > 0)
		rotate_a(data, 1);
	while (data->moves.rb-- > 0)
		rotate_b(data, 1);
	while (data->moves.rr-- > 0)
		rotate_rr(data, 1);
	while (data->moves.rra-- > 0)
		reverse_rotate_a(data, 1);
	while (data->moves.rrb-- > 0)
		reverse_rotate_b(data, 1);
	while (data->moves.rrr-- > 0)
		reverse_rotate_rrr(data, 1);
	if (f == 0)
		push_b(data, 1);
	else if (f == 1)
		push_a(data, 1);
}

void	three_sort(t_data *data)
{
	if ((data->a[0] < data->a[1]) && (data->a[0] < data->a[2])
		&& (data->a[1] > data->a[2]))
	{
		swap_a(data, 1);
		rotate_a(data, 1);
	}
	else if ((data->a[0] > data->a[1]) && (data->a[0] > data->a[2])
		&& (data->a[1] > data->a[2]))
	{
		swap_a(data, 1);
		reverse_rotate_a(data, 1);
	}
	else if ((data->a[0] < data->a[1]) && (data->a[0] > data->a[2])
		&& (data->a[1] > data->a[2]))
		reverse_rotate_a(data, 1);
	else if ((data->a[0] > data->a[1]) && (data->a[0] > data->a[2])
		&& (data->a[1] < data->a[2]))
		rotate_a(data, 1);
	else if ((data->a[0] > data->a[1]) && (data->a[0] < data->a[2])
		&& (data->a[1] < data->a[2]))
		swap_a(data, 1);
}
