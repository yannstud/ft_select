NAME        =   ft_select
FLAG        =   -Werror -Wall -Wextra -g3 #-fsanitize=address

PTH_LIBFT   =   libft/
LIBFT       =   $(PTH_LIBFT)libft.a
LNK_LIBFT   =   -L. $(LIBFT)

SRCS        =   srcs/main.c srcs/lists.c srcs/print.c srcs/parsing.c srcs/moove.c \

OBJ         =   $(SRCS:.c=.o)

INCLDS      =   -I $(PTH_LIBFT) -I ft_select.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	gcc $(FLAG) -lncurses -o $@ $^ $(LNK_LIBFT)

$(LIBFT):
	make re -C $(PTH_LIBFT)

%.o: %.c
	gcc $(FLAG) $(INCLDS) -c -o $@ $<

clean:
	rm -rf $(OBJ)
	make -C $(PTH_LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(PTH_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re