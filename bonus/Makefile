NAME = push_swap_bonus

SRC = checker.c utils_bonus.c rotate.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

cc = gcc

all : $(NAME)

$(NAME) : $(SRC) $(OBJ) push_swap_bonus.h
	$(cc)  $(FLAGS) $(SRC) -o $(NAME)

%.o:%.c

	$(cc) $(FLAGS) -c $<

fclean :

	rm -rf $(OBJ) $(NAME)
	
clean :
	rm -rf $(OBJ)
	
re : fclean all

	


