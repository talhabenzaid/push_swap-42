NAME		= push_swap

SRCS		= push_swap.c \
			  ft_split.c \
			  utils.c \
			  operations1.c \
			  operations2.c \
			  init.c \
			  init2.c \
			  push.c

b_srcs     = ft_split_bonus.c \
			checker_bonus.c \
			checker_utils_bonus.c\
			get_next_line_utils_bonus.c \
			get_next_line_bonus.c\
			read_bonus.c\
			operations1_bonus.c \
			operations2_bonus.c

OBJS		= $(SRCS:%.c=%.o)
b_objs		= $(b_srcs:%.c=%.o)

FLAGS		= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS)  $(OBJS) -o $@

%.o: %.c push_swap.h
	cc $(FLAGS) -c $< -o $@

bonus : checker

checker: $(b_objs)
	cc $(FLAGS) $(b_objs) -o $@

clean:
	rm -f $(OBJS) $(b_objs)

fclean: clean
	rm -f $(NAME) checker

re: fclean all