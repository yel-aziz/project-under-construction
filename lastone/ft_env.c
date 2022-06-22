/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:19:45 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/22 03:45:47 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	ft_env(void)
{
	t_list	*current;
	t_list	*last;

	current = *env;
	last = ft_lstlast(current);
	// free(last->part_two);
	// last->part_two = ft_strdup("/usr/bin/env");
	while (current)
	{
		printf("%s=%s\n", current->part_one, current->part_two);
		current = current->next;
	}
}