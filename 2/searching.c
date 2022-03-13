/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:23:43 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/13 21:28:26 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_search(int j)
{
	int	i;
	t_stack va;

	i = va.index_stack_temp;

	while (va.b[i] != j)
	{
		i--;
	}
	return (i);
}