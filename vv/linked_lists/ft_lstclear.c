/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:36:54 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/22 11:48:08 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curent;
	t_list	*next;

	curent = *lst;
	while (curent)
	{
		next = curent->next;
		ft_lstdelone(curent, del);
		curent = next;
	}
	*lst = NULL;
}
