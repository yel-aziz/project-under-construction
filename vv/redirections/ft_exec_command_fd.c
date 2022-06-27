/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:08:55 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/06/27 23:17:11 by yel-aziz         ###   ########.fr       */
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

void	ft_heredoc(char	**splited)
{
	int		i;
	char	*str;
	int		fd;

	i = 0;
	while (splited[i] && ft_strcmp(splited[i], "<<"))
		i++;
	if (fork() == 0)
	{
		fd = open("/tmp/.heredoc", O_CREAT | O_RDWR | O_TRUNC, 0664);
		if (fd < 0)
			printf("error occured I wanna go home\n");
		write(1, ">", 1);
		str = get_next_line(0);
		while (str && ft_strncmp(splited[i + 1], str,
				len_before_char(splited[i + 1], '\n') - 1))
		{
			write(fd, str, ft_strlen(str));
			free(str);
			write(1, ">", 1);
			str = get_next_line(0);
		}
		if (str)
			free(str);
		close(fd);
		exit(0);
	}
	wait(NULL);
	if (i)
		ft_heredoc_com(splited);
	unlink("/tmp/.heredoc");
}

void	ft_output_redirection(char **splited)
{
	char	*command;
	int		i;
	int		fd;

	i = 0;
	command = ft_find_cmd(splited);
	while (splited[++i]);
	ft_open(splited, i);
	if (!ft_strcmp(splited[i - 2], ">"))
		fd = open(splited[i - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	else if (ft_strcmp(splited[i - 2], ">>") == 0)
		fd = open(splited[i - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
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
	int		j;
	int		fd_inp;
	int		fd;

	j = 0;
	while (splited[j] && ft_strcmp(splited[j], "<"))
		j++;
	if (splited[j] && !ft_strcmp(splited[j], "<"))
	{
		command = ft_find_cmd(splited);
		fd_inp = open(splited[j - 1], O_RDONLY, 0644);
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
		close(fd);
		wait(NULL);
	}
}

void	ft_exec_fd(char	**splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		if (ft_strcmp(splited[i], "<<") == 0)
		{
			ft_heredoc(splited);
			break ;
		}
		if (ft_strcmp(splited[i], "<") == 0)
		{
			ft_input_redirection(splited);
			break ;
		}
		else if (ft_strcmp(splited[i], ">") == 0
			|| ft_strcmp(splited[1], ">>") == 0)
		{
			ft_output_redirection(splited);
			break ;
		}
		i++;
	}
}
