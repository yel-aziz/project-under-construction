NAME = push_swap

SRC =	push_swap.c utils_1.c rotate.c indexing.c push.c checker.c ft_sort.c checkme.c small_sort.c med_sort.c

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