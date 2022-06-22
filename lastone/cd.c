/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:48:30 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/20 05:33:04 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char **cmd)
{
	if (!cmd[1])
	{
		if (chdir(getenv("HOME")))
			perror("minishell : cd:");
	}
	else
	{
		if (chdir(cmd[1]))
			perror("minishell : cd ");
	}
}