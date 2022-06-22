/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:11:24 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/22 06:01:46 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_valid_quotes(char *command)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (command[i])
	{
		if (is_quote(command[i]) && !quote)
			quote = command[i++];
		if (quote)
			while (command[i] && command[i] != quote)
				i++;
		if (!command[i])
			return (0);
		quote = 0;
		i++;
	}
	return (1);
}

char	*parse_quotes(char *command)
{
	char	*parsed_command;
	int	i;

	parsed_command = command;
	i = 0;
	if (parsed_command[0] == '"' )
		parsed_command = ft_strtrim(parsed_command, "\"");
	else if (parsed_command[0] == '\'')
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
		parsed_command[i] = parse_quotes(parsed_command[i]);
		i++;
	}
	return (parsed_command);
}
