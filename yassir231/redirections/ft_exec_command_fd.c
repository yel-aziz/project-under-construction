/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:08:55 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/06/26 10:57:23 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

char	*ft_find_cmd(char **splited)
{
	int		i;
	char	*cmd;

	i = 0;
	cmd = ft_strdup(" ");
	while (splited[i])
	{
		if (!ft_strcmp(splited[i], ">") || !ft_strcmp(splited[i], ">>")
			|| !ft_strcmp(splited[i], "<") || !ft_strcmp(splited[i], "<<"))
			break ;
		cmd = ft_strjoin(cmd, splited[i]);
		cmd = ft_strjoin(cmd, " ");
		i++;
	}
	return (cmd);
}

// void	ft_heardoc_init(char**splited)
// {
// 	// int		i;
// 	// int		fd;
// 	// char	*line;
// 	// char	*name;
// 	// char	*to_right;

// 	// i = 0;
// 	// while (splited[i])
// 	// 	i++;
// 	// fd = -1;
// 	// line = ft_strdup(" ");
// 	// to_right = ft_strdup(" ");
// 	// if (ft_strcmp(splited[0], "<<") == 0)
// 	// {
// 	// 	while (line != NULL)
// 	// 	{
// 	// 		if (ft_strcmp_delimiteur(line, splited[1]) == 0)
// 	// 			break ;
// 	// 		line = get_next_line(0);
// 	// 		to_right = ft_strjoin(to_right, line);
// 	// 	}
// 	// 	if (splited[2] != NULL)
// 	// 	{
// 	// 		ft_open(splited, i);
// 	// 		if (ft_strcmp(splited[i - 2], ">") == 0)
// 	// 		{
// 	// 			name = parse_quotes(splited[i - 1]);
// 	// 			fd = open(name, O_RDWR | O_CREAT | O_TRUNC, 0644);
// 	// 		}
// 	// 		else if (ft_strcmp(splited[i - 2], ">>") == 0)
// 	// 		{
// 	// 			name = ft_strtrim(splited[i - 1], "\"");
// 	// 			name = ft_strtrim(splited[i - 1], "\"");
// 	// 			fd = open(name, O_RDWR | O_CREAT | O_APPEND, 0644);
// 	// 		}
// 	// 		ft_putstr_fd(to_right, fd);
// 	// 	}
// 	// }
// }

void	ft_output_redirection(char **splited)
{
	char	*command;
	char	*name;
	int		i;
	int		fd;

	i = 0;
	command = ft_find_cmd(splited);
	while (splited[++i]);
	ft_open(splited, i);
	name = parse_quotes(splited[i - 1]);
	if (!ft_strcmp(splited[i - 2], ">"))
		fd = open(name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	else if (ft_strcmp(splited[i - 2], ">>") == 0)
		fd = open(name, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fork() == 0)
	{
		dup2(fd, STDOUT_FILENO);
		execute_command(command);
		close(fd);
		exit(0);
	}
	close(fd);
	wait(NULL);	
}

void	ft_input_redirection(char **splited)
{
	char	*command;
	char	*name;
	int		i;
	int		j;
	int		fd_inp;
	int		fd;

	i = 0;
	j = 0;
	while(splited[i++]);
	while (splited[j])
	{
		if (ft_strcmp(splited[j], "<") == 0)
			break ;
		j++;
	}
	ft_open(splited, i);
	if (splited[j] &&!ft_strcmp(splited[j], "<"))
	{
		command = ft_find_cmd(splited);
		ft_open(splited, i);
		name = ft_strtrim(splited[j + 1], "\'");
		name = ft_strtrim(splited[j + 1], "\"");
		fd_inp = open(name, O_RDONLY, 0644);
		fd = extended(splited);
		if (fd_inp < 0)
			printf("file does not exist\n");
		else if (fork() == 0)
		{
			dup2(fd_inp, STDIN_FILENO);
			dup2(fd, STDOUT_FILENO);
			execute_command(command);
			close(fd_inp);
			close(fd);
			exit(0);
		}
		close(fd_inp);
		wait(NULL);
	}
}

void	ft_exec_fd(char	**splited)
{
	// if (ft_strcmp(splited[0], "<<") == 0)
	// 	ft_heardoc_init(splited);
	if (ft_strcmp(splited[1], ">") == 0 || ft_strcmp(splited[1], ">>") == 0)
		ft_output_redirection(splited);
	else if (ft_strcmp(splited[1], "<") == 0)
		ft_input_redirection(splited);
}
