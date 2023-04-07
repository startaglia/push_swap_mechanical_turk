/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: startagl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:10:04 by startagl          #+#    #+#             */
/*   Updated: 2023/04/07 12:59:05 by startagl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>

typedef struct s_moves
{
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	pa;
	int	pb;
}				t_moves;

typedef struct s_data
{
	int			*a;
	int			*b;
	int			index_string_a;
	int			len_a;
	int			len_b;
	int			max_a;
	int			min_a;
	int			index_max_a;
	int			index_min_a;
	int			half_index_a;
	int			half_index_b;
	int			major_index_num_a;
	int			minor_index_num_a;
	int			major_index_num_b;
	int			minor_index_num_b;
	int			max_b;
	int			min_b;
	int			index_max_b;
	int			index_min_b;
	int			n_moves;
	int			tot_moves;
	int			index_a_at_push;
	int			index_b_at_push;
	t_moves		moves;	

}				t_data;

void	ft_print_error(void);
void	ft_is_valid_num(char **av, int j);
void	fill_b_x(t_data *data);
void	ft_free_data(t_data *data);
void	ft_print_stacks(t_data	*data);
void	ft_print_stack_a(t_data	*data);
void	ft_print_stack_b(t_data	*data);
void	swap_a(t_data *data, int f);
void	swap_b(t_data *data, int f);
void	swap_ss(t_data *data, int f);
void	push_b(t_data *data, int f);
void	push_a(t_data *data, int f);
void	reverse_rotate_a(t_data *data, int f);
void	reverse_rotate_b(t_data *data, int f);
void	reverse_rotate_rrr(t_data *data, int f);
void	rotate_a(t_data *data, int f);
void	rotate_b(t_data *data, int f);
void	rotate_rr(t_data *data, int f);
void	ft_get_maximum_nums(t_data *data);
void	get_stacks_data(t_data *data);
void	cicle_a(t_data *data);
void	ft_sorting(t_data *data, int f);
void	init_moves(t_data *data);
void	cicle_b(t_data *data);
void	ft_ready_to_start(t_data *data, int f);
void	three_sort(t_data *data);
void	upper_half_utils_b(t_data *data, int i, int temp_moves);
void	upper_half_a_utils(t_data *data, int i, int temp_moves);
void	lower_half_utils_b(t_data *data, int i, int temp_moves);
void	lower_half_a_utils(t_data *data, int i, int temp_moves);
void	different_half_utils_b(t_data *data, int i, int temp_moves);
void	do_the_shit(t_data *data);
void	different_half_a_utils(t_data *data, int i, int temp_moves);
int		initialize_val(t_data *data, char *av[], int f);
int		find_major_a(t_data *data, int i);
int		find_minor_a(t_data *data, int i);
int		find_minor_b(t_data *data, int i);
int		ft_fill_a(t_data *data, char **av);
int		check_double(t_data *data);
int		ft_free_mem(char **matrix, int f);
int		ft_isdigit(int c);
int		ft_atoi(char *str);
int		check_start_sorted(t_data *data);
int		check_a_input_num(t_data *data);
int		check_a_max_num(t_data *data);
int		check_a_min_num(t_data *data);
int		check_b_max_num(t_data *data);
int		check_b_min_num(t_data *data);
int		check_a_max_num_index(t_data *data);
int		check_a_min_num_index(t_data *data);
int		check_b_max_num_index(t_data *data);
int		check_b_min_num_index(t_data *data);
int		find_spot_in_b(t_data *data, int i);
int		find_minor_b(t_data *data, int i);
int		get_input_num(char **av);
int		find_spot_in_a(t_data *data, int i);
int		find_major_b(t_data *data, int i);
int		find_middle_stack(t_data *data, int f);
char	**ft_split(char const *s, char c);

#endif