/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:45:36 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/10 16:21:09 by yel-aziz         ###   ########.fr       */
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
	va->index_stack_temp = -1;
	
	while (i <= va->index_stack)
	{
		j = 0;
		while (j <= va->index_stack)
		{
			if (i != j && va->a[i] > va->a[j])
			cnt++;
			j++;
		}
		va->b[i] = cnt;
		cnt = 0;
		i++;
	}
	va->index_stack_temp = i - 1;
}

void sort_index(t_stack *va)
{
	int	i;

	i = va->index_stack_temp;
	va->index_stack_final = -1;
	while (i >= 0)
	{
		if (va->b[i] < va->moyen_stack)
		{
			push_final(va->final,va->b[i],va);
		}
		i--;
	}
	
}

void find_big(t_stack *va)
{
	int	i;
	int	j;
	int	top;
	int	k;

	va->index_stack = -1;
	top = va->index_stack_final;
	i = va->index_stack_final;
	j = va->index_stack_final;
	k = 0;

	while (i >= 0)
	{
		if(va->final[i] > va->final[j])
		{
			j = i;
		}
		i--;
	}
		
	if(j == 0)
	{
		rrb(va);
		va->index_stack += 1;
		push(va->a,va->final[top],va);
	}

	if (j == top)
	{
		push(va->a,va->final[top],va);
		va->index_stack += 1;
	}

	if ( va->index_stack_final == 0)
	{
		push(va->a,va->final[top],va);
		va->index_stack += 1;
	}

	va->new = malloc(sizeof(int) * va->index_stack_final - 1);
	va->index_stack_final -= 1;
	j = va->index_stack_final;

	while (j >= 0 )
	{
		va->new[k] = va->final[j];
		k++;
		j--;
	}

	while (k >= 0)
	{
		va->final[j] = va->new[k];
		k--;
		j++;
	}
	k = 0;
}
