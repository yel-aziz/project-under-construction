NAME = parcing

SRCS = parcing_main.c utils_parcing.c get_next_line.c ft_exec_command_fd.c gn_utils.c valid_parame.c parcing.c

OBJS = $(SRCS:.c=.o)

FLAGS = -D BUFFER_SIZE=1

LDFLAGS := -L/goinfre/${USER}/.brew/opt/readline/lib
LDLIBS := -lreadline

all : $(NAME)

${NAME} : ${OBJS} parcing.h
	cc ${CFLAGS} ${LDFLAGS} ${LDLIBS} $(FLAGS) ${OBJS} -o ${NAME}

%.o : %.c
	cc  $(FLAGS) -c $<

clean : 
	rm -rf $(OBJS)
fclean :
	rm -rf $(OBJS) $(NAME)
re : fclean all

