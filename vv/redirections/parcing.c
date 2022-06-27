/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:42:58 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/06/27 23:24:54 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

void	ft_rederiction(char *cmd_byreadline)
{
	char	**splited;

	splited = split_parse_quotes(cmd_byreadline);
	ft_exec_fd(splited);
}

void	ft_special_copy(char *tmp, char *tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if (tab[i] == '>' && tab[i + 1] == ' ' && tab[i + 2] == '>')
		{
			tmp[j++] = '>';
			i += 2;
		}
		tmp[j++] = tab[i++];
	}
}

char	*traitment(char *cmd)
{
	int		i;
	int		j;
	char	*tab;
	char	*tmp;

	tab = ft_calloc(sizeof(char), 9999);
	tmp = ft_calloc(sizeof(char), 9999);
	j = 0;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '>' && cmd[i + 1] != ' ' && cmd[i - 1] != ' ')
		{
			tab[j] = ' ';
			tab[j + 1] = '>';
			j += 2;
			if (cmd[i + 1] == '>')
			{
				tab[j++] = '>';
				i++;
			}
			tab[j++] = ' ';
			i++;
		}
		else
		tab[j++] = cmd[i++];
	}
	ft_special_copy(tmp, tab);
	free(tab);
	return (tmp);
}

char	*traitment_layer_too(char *cmd)
{
	int		i;
	int		j;
	char	*tab;
	char	*tmp;

	i = 0;
	j = 0;
	while (cmd[i++]);
	tab = ft_calloc(sizeof(char), (i + 1));
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '<' && cmd[i + 1] != ' ')
		{
			tab[j++] = ' ';
			tab[j++] = '<';
			if (cmd[i + 1] == '<')
			{
				tab[j++] = '<';
				i++;
			}
			tab[j++] = ' ';
			i++;
		}
		tab[j++] = cmd[i++];
	}
	tmp = ft_calloc(sizeof(char), (j + 1));
	ft_special_copy(tmp, tab);
	return (tmp);
}
