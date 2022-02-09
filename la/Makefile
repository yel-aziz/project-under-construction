NAME  =  so_long

SRCS = so_long.c utils.c testeur_map.c converter.c finder.c rander.c walltest.c keyhoks_up_left.c keyhoks_down_right.c parcing_map.c utils_to.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)

all = $(NAME)

CC = gcc


$(NAME): $(SRCS) $(OBJ) so_long.h
	$(CC) $(FLAGS) $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Imlx -c $< -o $@

clean : 
	@rm -rf $(OBJ)

fclean : 
	@rm -rf $(OBJ) $(NAME)

re : fclean all
	
