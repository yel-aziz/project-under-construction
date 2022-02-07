NAME  =  so_long

SRCS = test.c utils.c testeur_map.c converter.c finder.c rander.c

FLAGS = 

OBJ = $(SRCS:.c=.o)

all = $(NAME)

CC = gcc


$(NAME): $(SRCS) $(OBJ) so_long.h
	$(CC) $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)



%.o: %.c
	$(CC) -Imlx -c $< -o $@
 	 


clean : 
	@rm -rf $(OBJ)

fclean : 
	@rm -rf $(OBJ) $(NAME)

re : fclean all
	
