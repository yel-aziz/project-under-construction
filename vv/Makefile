# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 15:20:29 by ysakine           #+#    #+#              #
#    Updated: 2022/06/27 05:43:17 by ysakine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := ft_split.c main.c utils.c prompt.c ft_strtrim.c ft_env.c ft_echo.c ft_pwd.c\
execute_binary.c parse_quotes.c check.c parse_redirections.c utils2.c redirections/ft_heredoc_utils.c\
cd.c linked_lists/ft_lstadd_back.c linked_lists/ft_lstadd_front.c linked_lists/ft_lstclear.c\
linked_lists/ft_lstdelone.c linked_lists/ft_lstlast.c linked_lists/ft_lstnew.c linked_lists/ft_lstsize.c\
linked_lists/ft_lstnew2.c ft_strdup.c export.c export_utils.c unset.c redirections/extended.c\
redirections/ft_exec_command_fd.c redirections/parcing.c redirections/parcing_main.c redirections/utils_parcing.c\
redirections/valid_parame.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
CFLAGS := -Wall -Wextra -Werror -I/goinfre/${USER}/.brew/opt/readline/include -D BUFFER_SIZE=1
LDFLAGS := -L/goinfre/${USER}/.brew/opt/readline/lib
LDLIBS := -lreadline
OBJS := ${SRCS:.c=.o}
NAME := minishell

${NAME} : ${OBJS}
	cc ${CFLAGS} ${LDFLAGS} ${LDLIBS} ${OBJS} -o ${NAME}

all : ${NAME}

clean :
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${NAME}

re : fclean ${NAME}