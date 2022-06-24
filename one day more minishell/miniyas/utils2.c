/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:30:10 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/17 22:10:28 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	count_commands(char **command)
{
	size_t	i;

	i = 0;
	while (command[i])
		i++;
	return (i);
}

void	create_pipes(int *fd, size_t len)
{
	size_t	j;

	j = 0;
	while (j < len)
	{
		pipe(&fd[j]);
		j += 2;
	}
}

void	wait_all(size_t len)
{
	size_t	i;

	i = 0;
	while (i++ < len)
		wait(&exit_status);
}
