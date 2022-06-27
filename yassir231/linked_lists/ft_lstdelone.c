/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:29:26 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/22 11:17:32 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		if (lst->part_one)
			del(lst->part_one);
		if (lst->part_two)
			del(lst->part_two);
		free(lst);
	}
}
