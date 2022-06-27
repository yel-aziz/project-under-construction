/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 05:00:17 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/27 23:32:05 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstswap(t_list *node0, t_list *node1)
{
	char	*tmp_part_one;
	char	*tmp_part_two;

	tmp_part_one = node0->part_one;
	tmp_part_two = node0->part_two;
	node0->part_one = node1->part_one;
	node0->part_two = node1->part_two;
	node1->part_one = tmp_part_one;
	node1->part_two = tmp_part_two;
}
