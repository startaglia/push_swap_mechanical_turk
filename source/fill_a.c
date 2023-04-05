/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:50:38 by startagl          #+#    #+#             */
/*   Updated: 2023/04/05 15:21:39 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_is_valid_num(char **av, int j)
{
	int		z;

	z = 0;
	while (av[j][z])
	{
		if (((av[j][z] == '-') && (!ft_isdigit(av[j][z + 1])))
		|| ((av[j][z] == '+') && (!ft_isdigit(av[j][z + 1]))))
			ft_print_error();
		if ((ft_isdigit(av[j][z])) || (av[j][z] == 32)
			|| (av[j][z] == '-') || (av[j][z] == '+'))
			z++;
		else
			ft_print_error();
	}
}

t_data	*get_multiple_input(t_data	*data, char **value_to_split)
{
	int	i;

	i = 0;
	while (value_to_split[i])
	{
		data->a[data->index_string_a] = ft_atoi(value_to_split[i]);
		data->index_string_a++;
		i++;
	}
	return (data);
}

int	ft_fill_a(t_data *data, char **av)
{
	int		j;
	int		i;
	char	**value_to_split;
	int		counter;

	counter = 0;
	j = 1;
	while (av[j])
	{
		i = 0;
		value_to_split = ft_split(av[j], 32);
		while (value_to_split[i])
			i++;
		if (i > 1)
			data = get_multiple_input(data, value_to_split);
		else
		{
			data->a[data->index_string_a] = ft_atoi(value_to_split[0]);
			data->index_string_a++;
		}
		j++;
		ft_free_mem(value_to_split, 1);
	}
	return (0);
}
