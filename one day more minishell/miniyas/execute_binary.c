/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:12:08 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/18 22:27:08 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	search_binary(char **bin_path, char **command)
{
	char	*tmp;
	int		i;

	tmp = ft_strjoin("/",command[0]);
	free(command[0]);
	command[0] = tmp;
	i = 0;
	while (bin_path[i])
	{
		tmp = ft_strjoin(bin_path[i], command[0]);
		if (access(tmp, X_OK) != -1)
		{
			free(tmp);
			break ;
		}
		free(tmp);
		i++;
	}
	if (!bin_path[i])
		return (0);
	execve(tmp, command, NULL);
	return (1);
}

void	execute_binary(char **command)
{
	char	**bin_path;
	char	*tmp;
	int		i;

	bin_path = ft_split(getenv("PATH"), ':');
	if (fork() == 0)
	{
		if (execve(command[0], command, NULL) == -1)
		{
			if (!search_binary(bin_path, command))
			{
				printf("\033[0;31m command not found\n\033[0m");
				exit(127);
			}
			exit(0);
		}
		wait(&exit_status);
		exit(exit_status);
	}
	wait(&exit_status);
	exit_status = WEXITSTATUS(exit_status);
	clear(bin_path);
}
