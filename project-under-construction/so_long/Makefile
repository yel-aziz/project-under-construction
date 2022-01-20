NAME  =  so_long

SRCS = test.c utils.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)

all = $(NAME)

CC = gcc


$(NAME): $(SRCS) $(OBJ) so_long.h
	$(CC) $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)



%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
 	 


clean : 
	@rm -rf $(OBJ)

fclean : 
	@rm -rf $(OBJ) $(NAME)

re : fclean all
	
