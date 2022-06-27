/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 03:19:49 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/22 03:47:36 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*search_env(t_list **env, char *part_one)
{
	t_list	*current;

	current = *env;
	while (current && ft_strncmp(part_one, current->part_one, len_before_char(part_one, '=') - 1))
		current = current->next;
	return (current);
}

void	copy_env(t_list *node, char	*p2)
{
	free(node->part_two);
	node->part_two = ft_strdup(p2 + len_before_char(p2, '=') + 1);
}