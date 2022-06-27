/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 04:27:15 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/22 04:34:51 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset(char	**command)
{
	t_list	*var;
	t_list	*current;
	t_list	*tmp;
	int		i;

	i = 0;
	current = *env;
	if (!command[1])
		printf("not enough args\n");
	else
	{
		while (command[i])
		{
			var = search_env(env, command[i]);
			if (var)
			{
				while (current->next != var)
					current = current->next;
				tmp = current->next->next;
				ft_lstdelone(current->next, free);
				current->next = tmp;
			}
			i++;
		}
	}
}