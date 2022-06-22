# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 15:20:29 by ysakine           #+#    #+#              #
#    Updated: 2022/06/22 04:34:28 by ysakine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := ft_split.c main.c utils.c prompt.c ft_strtrim.c ft_env.c ft_echo.c ft_pwd.c\
redirections.c execute_binary.c parse_quotes.c check.c parse_redirections.c utils2.c\
cd.c linked_lists/ft_lstadd_back.c linked_lists/ft_lstadd_front.c linked_lists/ft_lstclear.c\
linked_lists/ft_lstdelone.c linked_lists/ft_lstlast.c linked_lists/ft_lstnew.c linked_lists/ft_lstsize.c\
linked_lists/ft_lstnew2.c ft_strdup.c export.c export_utils.c unset.c
# get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
CFLAGS := -g -I/goinfre/${USER}/.brew/opt/readline/include -D BUFFER_SIZE=1
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