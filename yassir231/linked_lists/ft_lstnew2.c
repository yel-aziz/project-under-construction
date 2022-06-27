/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 02:47:51 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/22 15:27:28 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*ft_lstnew2(char *part_one, char *part_two)
{
	t_list	*ret;

	ret = malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	ret->part_one = part_one;
	ret->part_two = part_two;
	ret->next = NULL;
	return (ret);
}