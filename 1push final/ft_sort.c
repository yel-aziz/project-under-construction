/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 23:31:26 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/19 16:14:08 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void ft_sort(t_stack *va)
{

	int	i;
	int	j;
	int	s;
	int	action;

	i = va->index_stack;
	j = va->index_stack;

	while (va->index_stack >= 0)
	{
		action = (va->index_stack / 2);
		i = va->index_stack;
		j = va->a[va->index_stack];

		while (i >= 0)
		{
			if(va->a[i] > j)
			{
				j = va->a[i];
			}
			i--;
	}
	s = 0;
	while (s <= va->index_stack)
	{
		if(va->a[s] == j)
		break;
		s++;
	}
	
	if(s <= action)
	{
		while (va->a[va->index_stack] != j)
		{
			rra(va);
		}
		
	}
	else{
		while (va->a[va->index_stack] != j)
		{
			ra(va);
		}
	}
	push_b(va->b,va->a[va->index_stack],va);
	va->index_stack--;
	}
}

	
