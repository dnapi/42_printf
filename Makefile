NAME = libftprintf.a

SRC = ft_printbase.c ft_printf.c ft_printstr.c ft_strlen.c \
		ft_printchar.c ft_strchr.c 

FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -ruvcs $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	cc $(FLAGS) -c $^ -o $@ 

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
