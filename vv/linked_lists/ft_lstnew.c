/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:56:28 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/24 08:36:37 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ret;
	char	**splited_env;

	ret = malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	splited_env = ft_split(content, '=');
	ret->part_one = splited_env[0];
	ret->part_two = splited_env[1];
	free(splited_env);
	ret->next = NULL;
	return (ret);
}
