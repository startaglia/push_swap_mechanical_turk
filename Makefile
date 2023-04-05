SRC_M = main.c 

SRC = source/fill_a.c source/check_double.c source/check_start_sorted.c source/start_checking.c \
		source/check_spot_in_b.c source/check_spot_in_a.c source/ft_a_num_controls.c source/ft_b_num_controls.c \
		source/stacks_data.c source/ft_split.c source/ft_atoi.c source/ft_free_mem.c source/debug.c \
		source/check_spot_a_utils.c source/check_spot_b_utils.c \
		moves/swap.c moves/push.c moves/reverse_rotate.c moves/rotate.c \

OBJ_M = $(SRC_M:.c=.o)
OBJ = $(SRC:.c=.o)

NAME = push_swap
LIBRARY := incl/ft_printf/libftprintf.a
FTPRINTF := incl/ft_printf/
FLAG = -Wall -Werror -Wextra
CC = gcc -g3

%.o: %.c
	@$(CC) $(FLAG) $< -o $@ 
	
all : 
	@make -C $(FTPRINTF)
	@$(CC) $(FLAG) $(SRC_M) $(SRC) $(LIBRARY) -o $(NAME) 

clean: 
	@make fclean -C $(FTPRINTF)
	@rm -f $(OBJ)
	@rm -f $(OBJ_M)
	
fclean:	clean
	@rm -f $(NAME)

re:	fclean all clean

.PHONY : clean fclean src re all