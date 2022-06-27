/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 05:08:19 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/27 23:17:30 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_heredoc_com(char **splited)
{
	int		fd_inp;
	int		fd;
	char	*command;

	command = ft_find_cmd(splited);
	fd_inp = open("/tmp/.heredoc", O_RDONLY, 0664);
	if (fd_inp < 0)
		printf("error occured I wanna go home\n");
	fd = extended(splited);
	if (fork() == 0)
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
