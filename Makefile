NAME = push_swap

LIBFT_PATH = ./libft
LIBFT  = $(LIBFT_PATH)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS =	indexing.c\
		k-sort.c k-sort_utils.c\
		main_utils.c main.c\
		mini_sort.c\
		mvs_push.c mvs_reverse_rot.c mvs_rotate.c mvs_swap.c\
		parsing_0.c parsing_1.c\
		stack_utils.c

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

.PHONY: all clean fclean re