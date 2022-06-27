/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:48:30 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/24 23:41:46 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char **cmd)
{
	t_list	*var;
	t_list	*var1;

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
	var = search_env(env, "PWD");
	var1 = search_env(env, "OLDPWD");
	free(var1->part_two);
	var1->part_two = ft_strdup(var->part_two);
	free(var->part_two);
	var->part_two = getcwd(NULL, 1024);
}
