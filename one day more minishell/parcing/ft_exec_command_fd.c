/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:08:55 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/06/25 00:26:44 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

char    *ft_find_cmd(char    **splited)
{
    int i;
    char    *cmd;

    i = 0;

    cmd = ft_strdup(" ");
    while (splited[i])
    {
        if((ft_strcmp(splited[i],">") == 0) || (ft_strcmp(splited[i],">>") == 0) || (ft_strcmp(splited[i],"<") == 0 ) || (ft_strcmp(splited[i],"<<") == 0))
            break;
            cmd = ft_strjoin(cmd, splited[i]);
            cmd = ft_strjoin(cmd, " ");

        i++;
    }
    return(cmd);
}
    
void    ft_exec_fd(char **splited)
{
    char    *command;
    int     i;
    int     fd;
    int     fd_inp;
    int     j;
    char    *name;

    i = 0;
    j = 0;

    while (splited[i])
        i++;
    
        if(((ft_strcmp(splited[0],">") != 0) && (ft_strcmp(splited[0],">>") != 0) && (ft_strcmp(splited[0],"<") != 0 )&& (ft_strcmp(splited[0],"<<") != 0))
        && ((ft_strcmp(splited[1],">") != 0) && (ft_strcmp(splited[1],">>") != 0) && (ft_strcmp(splited[1],"<") != 0) && (ft_strcmp(splited[1],"<<") != 0)))
        {
            i = 0;
            command = ft_find_cmd(splited);
            // printf("cmd == %s\n",command);
            // command = ft_strdup(" ");
            // command = ft_strjoin(command, splited[0]);
            // command = ft_strjoin(command, " ");
            // command = ft_strjoin(command, splited[1]);
            while (splited[i])
            i++;
            ft_open(splited,i);
            name = ft_strtrim(splited[i - 1], "\'");
            name = ft_strtrim(splited[i - 1], "\"");
            if(ft_strcmp(splited[i - 2], ">") == 0)
            fd = open(name, O_CREAT|O_RDWR|O_TRUNC, 0644);
            else if(ft_strcmp(splited[i - 2], ">>") == 0)
            fd = open(name, O_CREAT|O_RDWR|O_APPEND, 0644);
            int pid = fork();
            if(pid == 0)
            {
                dup2(fd,STDOUT_FILENO);
                execute_command(command);
                exit(0);
            }
            wait(NULL);
        }
        else
        {
            i = 0;
            while (splited[i])
            i++;
            j = 0;
            while (splited[j])
            {
                if(ft_strcmp(splited[j],"<") == 0)
                break;
                j++;
            }
            if(splited[j + 2] == NULL)
            {
                ft_open(splited,i);
                name = ft_strtrim(splited[j + 1], "\'");
                name = ft_strtrim(splited[j + 1], "\"");
                fd_inp = open(name, O_RDWR, 0644);
                int pid = fork();
                if(pid == 0)
                {
                    dup2(fd_inp,STDIN_FILENO);
                    execute_command(splited[0]);
                    close(fd_inp);
                    exit(0);
                }
                wait(NULL);
            }
            else if (splited[j + 2] != NULL)
            {
                ft_open(splited,i);
                name = ft_strtrim(splited[j + 1], "\'");
                name = ft_strtrim(splited[j + 1], "\"");
                fd_inp = open(name, O_RDWR, 0644);
                name = ft_strtrim(splited[i - 1], "\'");
                name = ft_strtrim(splited[i - 1], "\"");
                if(ft_strcmp(splited[i - 2] , ">>") == 0)
                fd = open(name, O_RDWR|O_CREAT|O_APPEND, 0644);
                fd = open(name, O_RDWR|O_CREAT|O_APPEND, 0644);
                int pid = fork();
                if(pid == 0)
                {
                    dup2(fd_inp,STDIN_FILENO);
                    dup2(fd,STDOUT_FILENO);
                    execute_command(splited[0]);
                    close(fd);
                    close(fd_inp);
                    exit(0);
                }
                wait(NULL);
            }
            
        }
}