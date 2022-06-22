/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:28:57 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/13 20:03:43 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_pipe(char *command)
{
	int		i;
	char	quote_open;

	i = 0;
	quote_open = 0;
	while (command[i])
	{
		if(quote_open && command[i] == quote_open)
			quote_open = 0;
		else if (command[i] == '"' || command[i] == '\"' || command[i] == '`')
			quote_open = command[i++];
		if (command[i]  == '|' && !quote_open)
			return (1);
		i++;
	}
	return (0);
}

int	has_output_redirection(char *command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (command[i]  == '>')
			return (1);
		i++;
	}
	return (0);
}

int	has_input_redirection(char *command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (command[i]  == '<')
			return (1);
		i++;
	}
	return (0);
}
