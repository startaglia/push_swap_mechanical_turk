/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:18:13 by startagl          #+#    #+#             */
/*   Updated: 2023/04/05 15:04:37 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	long int	r;
	int			s;

	r = 0;
	s = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_print_error();
		r = r * 10 + (*str++) - 48;
	}
	if (r > 2147483647 || r < -2147483647)
		ft_print_error();
	return (r * s);
}
