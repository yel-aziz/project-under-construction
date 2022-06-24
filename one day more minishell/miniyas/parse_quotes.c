/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:11:24 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/10 13:21:19 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_valid_quotes(char *command)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (command[i])
	{
		if (command[i] == '"')
			j++;
		i++;	
	}
	i = 0;
	while (command[i])
	{
		if (command[i] == '\'')
			j++;
		i++;	
	}
	return (j % 2 == 0);
}

char	*parse_quotes(char *command)
{
	char	*parsed_command;
	int	i;

	parsed_command = command;
	i = 0;
	if (parsed_command[0] == '"' || parsed_command[ft_strlen(parsed_command) - 1] == '"')
		parsed_command = ft_strtrim(parsed_command, "\"");
	else if (parsed_command[0] == '\'' || parsed_command[ft_strlen(parsed_command) - 1] == '\'')
		parsed_command = ft_strtrim(parsed_command, "'");
	return (parsed_command);
}

char	**split_parse_quotes(char *command)
{
	char	**parsed_command;
	int		i;
	char	*tmp;

	i = 0;
	parsed_command = ft_split(command, ' ');
	while (parsed_command[i])
	{
		tmp = parse_quotes(parsed_command[i]);
		if (tmp != parsed_command[i])
			free(parsed_command[i]);
		parsed_command[i] = tmp;
		i++;
	}
	return (parsed_command);
}
