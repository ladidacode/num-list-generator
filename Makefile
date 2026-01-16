CC		=	gcc

CFLAGS	=	-Wextra -Werror -Wall -I ./include

SRC		=	generator.c			\
			error_handling.c	\

OBJ		=	$(SRC:.c=.o)

NAME	=	generator

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFFLAGS) -o $(NAME) $(OBJ)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
