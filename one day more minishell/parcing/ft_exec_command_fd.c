/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:08:55 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/06/26 01:17:18 by yel-aziz         ###   ########.fr       */
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

void    ft_heardoc_init(char    **splited)
{
    int     i;
    int     fd;
    char    *line;
    char    *name;
    char    *to_right;
    
    while (splited[i])
        i++;
        line = ft_strdup(" ");
        to_right = ft_strdup(" ");
    if(ft_strcmp(splited[0],"<<") == 0)
    {
        while (line !=NULL)
        {
           if(ft_strcmp_delimiteur(line, splited[1]) == 0)
            break;
            line = get_next_line(0);
            to_right = ft_strjoin(to_right, line);
        }
        if(splited[2] != NULL)
        {
            ft_open(splited,i);
            if(ft_strcmp(splited[i - 2], ">") == 0)
            {
                name = ft_strtrim(splited[i - 1], "\"");
                name = ft_strtrim(splited[i - 1], "\"");
                fd = open(name, O_RDWR|O_CREAT|O_TRUNC, 0644);
            }
            else if (ft_strcmp(splited[i - 2], ">>") == 0)
            {
                name = ft_strtrim(splited[i - 1], "\"");
                name = ft_strtrim(splited[i - 1], "\"");
                fd = open(name, O_RDWR|O_CREAT|O_APPEND, 0644);
            }
        ft_putstr_fd(to_right,fd);
        }
    }
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
        if(ft_strcmp(splited[0],"<<") == 0)
        ft_heardoc_init(splited);
        else if(ft_strcmp(splited[1],">") != 0 && ft_strcmp(splited[1],">>") != 0 && ft_strcmp(splited[1],"<") != 0 && ft_strcmp(splited[1],"<<") != 0 && ft_strcmp(splited[1],">") != 0 && ft_strcmp(splited[1],">>") != 0 && ft_strcmp(splited[1],"<") != 0 && ft_strcmp(splited[1],"<<") != 0)
        {
            printf("fiirst\n");
            i = 0;
            command = ft_find_cmd(splited);
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
        else if(ft_strcmp(splited[1],">") == 0 || ft_strcmp(splited[1],">>") == 0 || ft_strcmp(splited[1],"<") == 0 || ft_strcmp(splited[1],"<<") == 0)
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
            ft_open(splited,i);
            if(splited[j] && splited[j + 2] == NULL && ft_strcmp(splited[j], "<") == 0)
            {
                command = ft_find_cmd(splited);
                ft_open(splited,i);
                name = ft_strtrim(splited[j + 1], "\'");
                name = ft_strtrim(splited[j + 1], "\"");
                fd_inp = open(name, O_RDWR, 0644);
                int pid = fork();
                if(pid == 0)
                {
                    dup2(fd_inp,STDIN_FILENO);
                    execute_command(command);
                    close(fd_inp);
                    exit(0);
                }
                close(fd_inp);
                wait(NULL);
            }
            else if (splited[j] && splited[j + 2] != NULL && ft_strcmp(splited[j], "<") == 0)
            {
                command = ft_find_cmd(splited);
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
                    execute_command(command);
                    close(fd);
                    close(fd_inp);
                    exit(0);
                }
                close(fd);
                close(fd_inp);
                wait(NULL);
            }
            else
            {
                i = 0;
                command = ft_find_cmd(splited);
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
        }
            
}