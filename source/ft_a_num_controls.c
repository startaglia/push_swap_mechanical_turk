/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_num_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:46:35 by startagl          #+#    #+#             */
/*   Updated: 2023/04/05 15:21:31 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

// void	ft_is_valid_num(char **av, int j)
// {
// 	int		z;

// 	z = 0;
// 	while (av[j][z])
// 	{
// 		if (((av[j][z] == '-') && (!ft_isdigit(av[j][z + 1])))
// 		|| ((av[j][z] == '+') && (!ft_isdigit(av[j][z + 1]))))
// 			ft_print_error();
// 		if ((ft_isdigit(av[j][z])) || (av[j][z] == 32)
// 			|| (av[j][z] == '-') || (av[j][z] == '+'))
// 			z++;
// 		else
// 			ft_print_error();
// 	}
// }

int	check_a_input_num(t_data *data)
{
	if (data->len_a <= 3)
		return (0);
	else
		return (1);
}

int	check_a_max_num_index(t_data *data)
{
	int	i;
	int	max;
	int	index;

	i = 0;
	index = 0;
	max = data->a[i];
	while (i < data->len_a)
	{
		if (data->a[i] > max)
		{
			max = data->a[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	check_a_max_num(t_data *data)
{
	int	i;
	int	max;

	i = 0;
	max = data->a[i];
	while (i < data->len_a)
	{
		if (data->a[i] > max)
			max = data->a[i];
		i++;
	}
	return (max);
}

int	check_a_min_num_index(t_data *data)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	index = 0;
	min = data->a[i];
	while (i < data->len_a)
	{
		if (data->a[i] < min)
		{
			min = data->a[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	check_a_min_num(t_data *data)
{
	int	i;
	int	min;

	i = 0;
	min = data->a[i];
	while (i < data->len_a)
	{
		if (data->a[i] < min)
			min = data->a[i];
		i++;
	}
	return (min);
}
