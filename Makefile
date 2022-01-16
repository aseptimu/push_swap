NAME = push_swap

BONUS_NAME = checker

LIB_NAME = libft/libft.a

SRCS_NAME  =	main.c check_args.c push_swap.c \
				operations.c sort_little.c scores_calc.c \
				operations_do.c sort.c scores_findmin.c \
				mid.c

SRCS_BONUS_NAME =	checker_bonus.c check_args_bonus.c \
					get_next_line.c get_next_line_utils.c \
					operations_bonus.c do_instructions.c

SRCS = $(addprefix src/, $(SRCS_NAME))

SRCS_BONUS = $(addprefix bonus/, $(SRCS_BONUS_NAME)) 

OBJS = $(patsubst %.c, %.o, $(SRCS))

OBJS_BONUS = $(patsubst %.c, %.o, $(SRCS_BONUS)) 

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = push_swap.h

HEADER_BONUS = push_swap_bonus.h get_next_line.h

LIB_HEADER = libft/libft.h

all : $(NAME)

$(NAME) : $(LIB_NAME) $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

src/%.o : src/%.c $(HEADER) $(LIB_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_NAME) : libft ;

libft :
	$(MAKE) bonus -C libft/

bonus : $(NAME) $(BONUS_NAME)

$(BONUS_NAME) : $(LIB_NAME) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $^ -o $(BONUS_NAME)

bonus/%.o : bonus/%.c $(HEADER_BONUS) $(LIB_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(MAKE) clean -C libft/ 
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(MAKE) fclean -C libft 
	rm -rf $(NAME) $(BONUS_NAME)

re : fclean all

.PHONY	: all clean fclean re libft