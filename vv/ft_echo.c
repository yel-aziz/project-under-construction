/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:19:34 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/27 23:08:02 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **str)
{
	int	index;
	int	flag;

	flag = 0;
	index = 1;
	while (str[index] && !ft_strcmp("-n", str[index]))
		index++;
	if (index > 1)
		flag = 1;
	while (str[index])
	{
		if (!ft_strcmp("$?", str[index]))
			printf("%d", (*env)->exit_status);
		else if (str[index][0] == '$')
		{
			if (search_env(env, &str[index][1]))
				printf("%s", search_env(env, &str[index][1])->part_two);
		}
		else if (str[index])
			printf("%s", str[index]);
		if (str[index + 1])
			printf(" ");
			index++;
	}
	if (!flag)
		printf("\n");
	(*env)->exit_status = 0;
}
