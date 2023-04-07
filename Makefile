# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: startagl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 12:06:43 by startagl          #+#    #+#              #
#    Updated: 2023/04/07 14:17:55 by startagl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = checker

SRC = main.c source/init.c source/fill_a.c source/check_double.c \
		source/check_start_sorted.c source/start_checking.c \
		source/check_spot_in_b.c source/check_spot_in_a.c source/ft_a_num_controls.c source/ft_b_num_controls.c \
		source/stacks_data.c source/ft_split.c source/ft_atoi.c source/ft_free_mem.c source/debug.c \
		source/check_spot_a_utils.c source/check_spot_b_utils.c \
		moves/swap.c moves/push.c moves/reverse_rotate.c moves/rotate.c \

SRC_B = bonus/checker.c incl/get_next_line/get_next_line.c \
		incl/get_next_line/get_next_line_utils.c 

OBJ = ${SRC:.c=.o}
OBJ_B = ${SRC_B:.c=.o}
OUT = ${filter-out main.o ,${OBJ}}

LIBRARY = incl/ft_printf/libftprintf.a
FTPRINTF = incl/ft_printf/
FLAG = -Wall -Werror -Wextra
CC = gcc -g3

.c.o:
	@${CC} -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	@make -C $(FTPRINTF)
	@$(CC) $(FLAG) $(OBJ) $(LIBRARY) -o $(NAME) 
	
all: ${NAME}

bonus: $(NAME) $(OBJ_B)
	@$(CC) $(FLAG) $(OUT) $(OBJ_B) $(LIBRARY) -o $(NAME_B)

clean:
	@make fclean -C $(FTPRINTF)
	@rm -f $(OBJ)
	@rm -f $(OBJ_B)
	
fclean:	clean
	@rm -f $(NAME)
	@rm -f $(NAME_B)

re:	fclean all clean

.PHONY : clean fclean re all