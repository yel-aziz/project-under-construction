NAME = push_swap

SRC =	push_swap.c utils_1.c swap.c rotate.c  indexing.c push.c 

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

cc = gcc

all : $(NAME)

$(NAME) : $(SRC) $(OBJ) 

	$(CC) $(FLAGS) $(SRC) -o $(NAME)

%.o : %.c

	$(cc) $(FLAGS) -c $<


clean :

	rm -rf $(OBJ)

fclean :

	rm -rf $(OBJ) $(NAME) 

re : fclean all