/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:19:45 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/27 23:08:29 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(void)
{
	t_list	*current;
	t_list	*last;

	current = *env;
	last = ft_lstlast(current);
	while (current)
	{
		printf("%s=%s\n", current->part_one, current->part_two);
		current = current->next;
	}
}
