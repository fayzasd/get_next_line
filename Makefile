NAME		= libft.a

SRCS		= get_next_line.c \
			  get_next_line_utils.c \

OBJS		= $(SRCS:%.c=%.o)
BOBJS		= $(BSRCS:%.c=%.o)
FLAGS		= -Wall -Werror -Wextra

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I ./
	ar rc $(NAME) $(OBJS)

bonus: $(NAME)
	gcc $(FLAGS) -c $(BSRCS) -I ./
	ar rc $(NAME) $(BOBJS)

all: $(NAME)

clean:
	rm -f $(OBJS) $(BOBJS)


fclean: clean
	rm -f $(NAME) 

re: fclean all bonus