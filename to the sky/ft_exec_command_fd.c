/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:08:55 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/06/23 23:48:35 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

void    ft_exec_fd(char **splited)
{
    char    *command;
    int     i;
    int     fd;
    int     j;
    char    *name;

    i = 0;
    j = 0;

        if((ft_strcmp(splited[0],">") != 0) && (ft_strcmp(splited[0],">>") != 0) && (ft_strcmp(splited[0],"<") != 0 )&& (ft_strcmp(splited[0],"<<") != 0)
        && (ft_strcmp(splited[1],">") != 0) && (ft_strcmp(splited[1],">>") != 0) && (ft_strcmp(splited[1],"<") != 0) && (ft_strcmp(splited[1],"<<") != 0))
        {
            command = ft_strdup(" ");
            command = ft_strjoin(command, splited[0]);
            command = ft_strjoin(command, " ");
            command = ft_strjoin(command, splited[1]);
         
         while (splited[i])
         i++;
         name = ft_strtrim(splited[i - 1], "\'");
         name = ft_strtrim(splited[i - 1], "\"");
         if(ft_strcmp(splited[i - 2], ">") == 0)
         fd = open(name, O_CREAT|O_RDWR|O_TRUNC, 0644);
         else if(ft_strcmp(splited[i - 2], ">>") == 0)
         fd = open(name, O_CREAT|O_RDWR|O_APPEND, 0644);
         dup2(fd,STDOUT_FILENO);
         ft_open(splited,i);
        }


}