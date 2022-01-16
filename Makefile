NAME = push_swap

LIB_NAME = libft/libft.a

SRCS_NAME  = main.c check_args.c push_swap.c \
			operations.c sort_little.c scores_calc.c \
			operations_do.c sort.c scores_findmin.c \
			mid.c


SRCS = $(addprefix src/, $(SRCS_NAME))

OBJS = $(patsubst %.c, %.o, $(SRCS))

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

HEADER = push_swap.h

LIB_HEADER = libft/libft.h

all : $(NAME)

$(NAME) : $(LIB_NAME) $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o : %.c $(HEADER) $(LIB_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_NAME) : libft ;

libft :
	$(MAKE) bonus -C libft/

clean :
	$(MAKE) clean -C libft/ 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C libft 
	rm -rf 

re : fclean all

.PHONY	: all clean fclean re libft

n : 
	norminette $(SRCS) $(HEADER)
run : all
	./push_swap 8 5 7 
count : all
	./push_swap 8 5 7 | wc -l