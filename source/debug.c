/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:41:31 by startagl          #+#    #+#             */
/*   Updated: 2023/04/05 15:08:52 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

// void	fill_b_x(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->len_b)
// 	{
// 		data->b[i] = '\0';
// 		i++;
// 	}
// }

// void	ft_print_stacks(t_data	*data)
// {
// 	int		i;

// 	i = 0;
// 	ft_printf("\n\t####### STACK A #######\t\t\t####### STACK B #######\n");
// 	while (i < data->len_a)
// 	{
// 		if (data->b[i] == '\0')
// 			ft_printf("\t\t%d\t\t\t\t\tX\n", data->a[i]);
// 		else
// 			ft_printf("\t\t%d\t\t\t\t\t%d\n", data->a[i], data->b[i]);
// 		i++;
// 	}
// }

void	ft_print_stack_a(t_data	*data)
{
	int	i;

	i = 0;
	ft_printf("\t####### STACK A #######\n");
	while (i < data->len_a)
		ft_printf("\t\t%d\n", data->a[i++]);
	ft_printf("\n");
}

void	ft_print_stack_b(t_data	*data)
{
	int	i;

	i = 0;
	ft_printf("\t####### STACK B #######\n");
	while (i < data->len_b)
		ft_printf("\t\t%d\n", data->b[i++]);
	ft_printf("\n\n\n");
}
