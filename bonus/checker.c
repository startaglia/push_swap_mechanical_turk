/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:01:11 by startagl          #+#    #+#             */
/*   Updated: 2023/04/05 16:30:33 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	esc_error(t_data *data)
{
	free(data->a);
	free(data->b);
	write(2, "Error\n", 6);
	exit(0);
}

int	check_move(char *move, int data)
{
	if (!ft_strcmp(move, "sa\n"))
		swap_a(data, 0);
	if (!ft_strcmp(move, "sb\n"))
		swap_b(data, 0);
	if (!ft_strcmp(move, "ss\n"))
		swap_s(data, 0);
	if (!ft_strcmp(move, "pa\n"))
		push_a(data, 0);
	if (!ft_strcmp(move, "pb\n"))
		push_b(data, 0);
	if (!ft_strcmp(move, "ra\n"))
		rotate_a(data, 0);
	if (!ft_strcmp(move, "rb\n"))
		rotate_b(data, 0);
	if (!ft_strcmp(move, "rr\n"))
		rotate_rr(data, 0);
	if (!ft_strcmp(move, "rra\n"))
		reverse_rotate_a(data, 0);
	if (!ft_strcmp(move, "rrb\n"))
		reverse_rotate_b(data, 0);
	if (!ft_strcmp(move, "rrr\n"))
		reverse_rotate_rrr(data, 0);
	else
		esc_error(data);
}

int main(int ac, char *av[])
{
	t_data	*data;
	char	*move;

	data = malloc(sizeof(t_data));
	initialize_val(data, av);
	move = get_next_line(0);
	while (move)
	{
		check_move(move, data);
		free(move);
		move = get_next_line(0);
	}
	free(move);
	if (check_start_sorted(data) && data->len_b == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_data(data);
}