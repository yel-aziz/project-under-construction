/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:45:36 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/19 16:19:34 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void indexing(t_stack *va)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	j = 0;
	cnt = 0;
	while (i <= va->index_stack)
	{
		j = 0;
		while (j <= va->index_stack)
		{
			if (i != j && va->a[i] > va->a[j])
			cnt++;
			j++;
		}

		push_b(va->b,cnt,va);
		cnt = 0;
		i++;
	}
}

void sort_index(t_stack *va)
{
	int	n;
	int cnt;
	int	i;

	n = 1;
	cnt = 0;
	va->index_stack = -1;
	i = va->index_stack_temp;
	
	while (va->index_stack_temp >= 0)
	{
		if(va->b[va->index_stack_temp] < (va->moyen_stack * n))
		{
			 push(va->a,va->b[va->index_stack_temp],va);
			 va->index_stack_temp--;
			 cnt++;
		}

		else
		{
			rb(va);
		}
		if(cnt == (va->moyen_stack * n))
		{
			n++;
		}
	}
		
}