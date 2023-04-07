/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:27:35 by startagl          #+#    #+#             */
/*   Updated: 2023/04/05 16:15:08 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_free_data(t_data *data)
{
	free(data->a);
	free(data->b);
	free(data);
}

int	ft_free_mem(char **matrix, int f)
{
	int	i;

	i = 0;
	if (f == 1)
	{
		while (matrix[i])
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
		return (1);
	}
	return (0);
}
