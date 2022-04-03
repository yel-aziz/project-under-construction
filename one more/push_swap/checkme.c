/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkme.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:42:36 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/30 21:13:57 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkme(t_stack *va)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= va->index_stack - 1)
	{
		j = i + 1;
		while (j <= va->index_stack)
		{
			if (va->a[i] > va->a[j])
			{
				j++;
			}
			else
			{
				return (0);
			}
		}	
		i++;
	}
	return (1);
}

int	checkme(t_stack *va)
{
	int	i;

	i = 0;
	while (i < va->index_stack)
	{
		if (va->a[i] < va->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
