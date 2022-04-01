NAME = checker

SRC = checker.c utils_bonus.c rotate.c get_next_line.c get_next_line_utils.c utlis_to.c

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

	


