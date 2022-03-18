/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 23:31:26 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/13 22:11:19 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void ft_sort(t_stack *va)
{
	int i;
	int j;
	int	s;
	int	action;
	
	i = va->index_stack_temp;
	j = va->index_stack_temp;
	
	
	while (va->index_stack_temp >= 0)
	{
		action = (va->index_stack_temp / 2);
		j = va->b[va->index_stack_temp];
		i = va->index_stack_temp;
		while (i >= 0)
		{
			if(va->b[i] > j)
			{
				j = va->b[i];
			}
				i--;
		}
		s = 0;
		while (s <= va->index_stack_temp)
		{
			if(va->b[s] == j)
			break;
			s++;
		}
		if(s <= action)
		{
			while (va->b[va->index_stack_temp] != j)
			{
				rrb(va);
			}
		}
		else
		{
			while (va->b[va->index_stack_temp] != j)
			{
				rb(va);
			}
		}
		
		push(va->a,va->b[va->index_stack_temp],va); 
		va->index_stack_temp--;
		
	}

}
	