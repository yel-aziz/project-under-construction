/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:55:42 by ysakine           #+#    #+#             */
/*   Updated: 2022/05/24 18:32:09 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	append_redirections(char *command)
{
	char	**splited_command;
	size_t	i;
	size_t	count;
	int		fd;

	i = 1;
	splited_command = ft_split(command, '>');
	count = count_commands(splited_command);
	while (i < count)
	{
		fd = open(splited_command[i], O_CREAT);
		i++;
		close(fd);
	}
	i--;
	fd = open(splited_command[i], O_APPEND);
	dup2(fd, STDOUT_FILENO);
	execute_command(splited_command[0]);
	close(fd);
}