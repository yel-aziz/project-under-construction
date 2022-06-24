/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:16:08 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/16 09:41:52 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_valid_pipes(char *command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (command[i] == '|' && command[i + 1] == '|')
			return (0);
		if (command[i] == '|' && !command[i + 1])
			return (0);
		i++;
	}
	return (1);
}

char	**split_pipe(char *command)
{
	char	**parsed_command;
	int		i;

	i = 0;
	parsed_command = ft_split(command, '|');
	while (parsed_command[i])
	{
		parsed_command[i] = ft_strtrim(parsed_command[i], " \"'");
		i++;
	}
	return (parsed_command);
}

char	**split_right_arrow(char *command)
{
	return (ft_split(command, '>'));
}

char	**split_left_arrow(char *command)
{
	return (ft_split(command, '<'));
}
