NAME = philosophers

SRCS = philo_main.c utils_one.c sharing.c  parcing.c 

OBJ = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCS) $(OBJ)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

fclean : 
	rm -rf $(OBJ) $(NAME)
clean :
	rm -rf $(OBJ)
re : fclean all