/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:01:11 by startagl          #+#    #+#             */
/*   Updated: 2023/04/07 16:41:54 by startagl         ###   ########.fr       */
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

int	check_move(char *move, t_data *data)
{
	if (ft_strcmp(move, "sa\n") == 0)
		swap_a(data, 0);
	else if (ft_strcmp(move, "sb\n") == 0)
		swap_b(data, 0);
	else if (ft_strcmp(move, "ss\n") == 0)
		swap_ss(data, 0);
	else if (ft_strcmp(move, "pa\n") == 0)
		push_a(data, 0);
	else if (ft_strcmp(move, "pb\n") == 0)
		push_b(data, 0);
	else if (ft_strcmp(move, "ra\n") == 0)
		rotate_a(data, 0);
	else if (ft_strcmp(move, "rb\n") == 0)
		rotate_b(data, 0);
	else if (ft_strcmp(move, "rr\n") == 0)
		rotate_rr(data, 0);
	else if (ft_strcmp(move, "rra\n") == 0)
		reverse_rotate_a(data, 0);
	else if (ft_strcmp(move, "rrb\n") == 0)
		reverse_rotate_b(data, 0);
	else if (ft_strcmp(move, "rrr\n") == 0)
		reverse_rotate_rrr(data, 0);
	else
		esc_error(data);
	return (0);
}

int	main(int ac, char *av[])
{
	t_data	*data;
	char	*move;

	if (ac > 1)
	{
		data = malloc(sizeof(t_data));
		initialize_val(data, av, 1);
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
	return (0);
}
