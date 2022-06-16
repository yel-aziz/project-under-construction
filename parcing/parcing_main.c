/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:50:13 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/06/16 05:20:31 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

void	get_line(int fd, int fd_direction)
{
	char	*line;

	while (line != NULL)
	{
		line = get_next_line(fd);
		ft_putstr_fd(line, fd_direction);
	}
	exit(0);
}

void	get_line_delimiter(int fd, int fd_direction, char *delimiter)
{
	char	*line;

	while (1) 
	{
		line = get_next_line(0);
        if (!line || !ft_strcmp_delimiteur(line, delimiter))
           exit (0); 
        ft_putstr_fd(line, fd_direction);
	}
    close(fd_direction);
    exit(0);
}

void    ft_open(char    **str, int   i)
{
    int fd;
    int j;
    char    *name;

    j = 0;
    
     i -= 1;
    while (j < i)
    {
        if (ft_strcmp(str[0],"cat") == 0 )
            j++;
        if (ft_strcmp(str[j],">") == 0 || ft_strcmp(str[j],">>") == 0 || ft_strcmp(str[j],"<") == 0 || ft_strcmp(str[j],"<<") == 0)
            j++;
        name = ft_strtrim(str[j++],"\"");
        fd = open(name,O_CREAT, 0666);
    }
}

// void    ft_parcing(char *cmd)
// {
//     int     i;
//     char    *file_name;
//     char    **names;
    
//     i = 0;
//     while (cmd[i])
//     i++;

//     file_name = malloc(sizeof(char *) * (i + 1));
//     if(!file_name)
//         exit(0);
//     i = 0;
//     while (cmd[i])
//     {
//         if(cmd[i] == '>'  || cmd[i] == '<')
//         {
//             file_name[i] = ' ';
//             i++;
//         }
//         file_name[i] = cmd[i];
//         i++;
//     }
//     file_name[i] = '\0';
// }

void    ft_lastone(char **splited, int i)
{
    int     fd;
    char    *name;
    
    // if (ft_strcmp(">", splited[i - 2]) == 0)
    // {
    //     printf("3adi 1");
    //     ft_open(splited, i);
    //     name = ft_strtrim(splited[i - 1],"\"");
    //     fd = open(name, O_RDWR|O_CREAT|O_TRUNC, 0666);
    //     if(ft_strcmp("cat",splited[0]) == 0)
    //     get_line(0, fd);
        
    // }
    // else if (ft_strcmp(">>", splited[i - 2]) == 0)
    // {
    //     printf("3adi 2");
    //     ft_open(splited, i);
    //     name = ft_strtrim(splited[i - 1],"\"");
    //     fd = open(name, O_RDWR|O_APPEND, 0666);
    //     if(ft_strcmp("cat",splited[0]) == 0)
    //     get_line(0, fd);
    // }
    if (ft_strcmp("<<", splited[i - 2]) == 0)
    {
        ft_open(splited, i);
        name = ft_strtrim(splited[i - 1],"\"");
        fd = open(name,O_RDWR|O_CREAT|O_TRUNC, 0666);
        get_line_delimiter(0, fd, splited[i - 1]);
    }
}

int main()
{
    char *cmd;
    char *tab;
    char    **spl;
    
    cmd = readline("\033[0;36m myShell$> \033[0m");

    if(ft_valid_parame(cmd) == 0)
    {
        tab =  traitment(cmd);
        tab = traitment_layer_too(tab);
        ft_rederiction(tab);
    }
}