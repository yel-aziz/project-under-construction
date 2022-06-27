/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:12:08 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/27 22:59:30 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	search_binary(char **bin_path, char **command)
{
	char	*tmp;
	int		i;

	tmp = ft_strjoin("/", command[0]);
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

	bin_path = ft_split(search_env(env, "PATH")->part_two, ':');
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
		wait(&(*env)->exit_status);
		exit((*env)->exit_status);
	}
	wait(&(*env)->exit_status);
	(*env)->exit_status = WEXITSTATUS((*env)->exit_status);
	clear(bin_path);
}
