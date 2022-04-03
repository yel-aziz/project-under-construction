NAME = checker

SRCS = checker.c utils_again.c action_zero.c last_check.c utils_bonus.c push_stack.c rotate_b.c get_next_line_utils.c get_next_line.c 

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

cc = gcc 

$(NAME) : $(SRCS) $(OBJ) push_swap_bonus.h
	cc $(FLAGS) $(SRCS) -o $(NAME)
	@echo ------COMPILED--------

%.o : %.c
	cc $(FLAGS) -c $<
fclean :
	rm -rf $(NAME) $(OBJ)

clean : 
	rm -rf $(OBJ)

re : fclean all