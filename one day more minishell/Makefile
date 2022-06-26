
SRCS = miniyas/ft_split.c miniyas/main.c miniyas/utils.c miniyas/prompt.c miniyas/ft_strtrim.c miniyas/ft_env.c miniyas/ft_echo.c miniyas/ft_pwd.c\
		miniyas/redirections.c miniyas/execute_binary.c miniyas/parse_quotes.c miniyas/check.c miniyas/parse_redirections.c miniyas/utils2.c\
			parcing/parcing_main.c miniyas/get_next_line/get_next_line.c miniyas/get_next_line/get_next_line_utils.c parcing/valid_parame.c\
			parcing/parcing.c parcing/utils_parcing.c parcing/ft_exec_command_fd.c parcing/gn_utils.c\

OBJS = $(SRCS:.c=.o)
CFLAGS := -g -I/goinfre/${USER}/.brew/opt/readline/include -D BUFFER_SIZE=1
LDFLAGS := -L/goinfre/${USER}/.brew/opt/readline/lib
LDLIBS := -lreadline
OBJS := ${SRCS:.c=.o}
NAME := minishell

${NAME} : ${OBJS}
	@echo -----compiling...--------
	@cc ${CFLAGS} ${LDFLAGS} ${LDLIBS} ${OBJS} -o ${NAME}

%.o : %.c
	@cc  $(CFLAGS) -c $< -o $@
	
all : ${NAME}

clean :
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${NAME}

re : fclean ${NAME}
