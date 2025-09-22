NAME = push_swap

LIBFT_PATH = ./libft
LIBFT  = $(LIBFT_PATH)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
DBGFLAGS = -DDEBUG
RM = rm -f

SRCS =  push_swap.c\
		parsing_0.c parsing_1.c\
		movements_0.c movements_1.c movements_2.c movements_3.c\
		stack_core.c\
		indexing.c\
		mini_sort.c\
		debug.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

debug: $(LIBFT)
	$(CC) $(CFLAGS) $(DBGFLAGS) $(SRCS) $(LIBFT) -o push_swap_debug

.PHONY: all clean fclean re debug