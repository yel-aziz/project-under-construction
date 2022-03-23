/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:27:10 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/23 23:03:45 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void med_sort(t_stack *va)
{
	int	i;
	int	j;
	int	s;
	int	action;

	i = va->index_stack;
	j = va->index_stack;
	action = 2;

	while (action > 0)
	{
			i = va->index_stack;
			j = va->index_stack;
			while (i >= 0)
			{
				if(va->a[i] < j)
				j = va->a[i];
				i--;
			}
	
		s = 0;
	while (s <= va->index_stack)
	{
		if(va->a[s] == j)
		break;
		s++;
	}

	if(s < (va->index_stack / 2))
	{
		while (va->a[va->index_stack] != j)
		{
			rra(va);
		}
	}
	else
	{
		while (va->a[va->index_stack] != j)
		{
			ra(va);
		}
		
	}
	push_b(va->b, va->a[va->index_stack], va);
	va->index_stack--;
	action--;
	}
	ft_small(va);
	print_table(va->a,va->index_stack);
	printf("\n");
	print_table(va->b,va->index_stack_temp);
}