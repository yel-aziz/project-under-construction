/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:50:13 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/06/27 02:27:47 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

void	ft_open(char **str, int i)
{
	int		fd;
	int		j;
	char	*name;

	j = 2;
	i -= 2;
	while (j < i)
	{
		if (ft_strcmp(str[j], ">") == 0 || ft_strcmp(str[j], ">>") == 0
			|| ft_strcmp(str[j], "<") == 0 || ft_strcmp(str[j], "<<") == 0)
			j++;
		name = parse_quotes(str[j++]);
		fd = open(name, O_CREAT | O_RDWR, 0644);
	}
}

void	ft_main_yassir(char *cmd)
{
	char	*tab;

	if (has_valid_quotes(cmd))
	{
		tab = traitment(cmd);
		tab = traitment_layer_too(tab);
		ft_rederiction(tab);
	}
}
