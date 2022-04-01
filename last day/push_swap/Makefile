NAME = push_swap

SRC =	push_swap.c  utils_1.c rotate.c indexing.c push.c  ft_sort.c checker.c checkme.c med_sort.c small_sort.c ft_split.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror 

cc = gcc

all : $(NAME)

$(NAME) : $(SRC) $(OBJ) push_swap.h

	$(CC) $(FLAGS) $(SRC) -o $(NAME)

%.o : %.c
	$(cc) $(FLAGS) -c $<

clean :

	rm -rf $(OBJ)

fclean :

	rm -rf $(OBJ) $(NAME) 

re : fclean all