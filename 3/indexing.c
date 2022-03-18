/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:45:36 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/13 22:24:45 by yel-aziz         ###   ########.fr       */
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

	n = 1;
	cnt = 0;
	
	va->index_stack_final = -1;
	while (va->index_stack_temp >= 0)
	{
		if(va->b[va->index_stack_temp] < (va->moyen_stack * n))
		{
			push_final(va->final,va->b[va->index_stack_temp],va);
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

	while (va->index_stack_final >= 0)
	{
		push_b(va->b,va->final[va->index_stack_final],va);
		va->index_stack_final--;
	}
	

		
}

// void find_big(t_stack *va)
// {
// 	int	i;
// 	int	j;
// 	int	top;
// 	int	k;

// 	va->index_stack = -1;
// 	top = va->index_stack_final;
// 	i = va->index_stack_final;
// 	j = va->index_stack_final;
// 	k = 0;

// 	while (i >= 0)
// 	{
// 		if(va->final[i] > va->final[j])
// 		{
// 			j = i;
// 		}
// 		i--;
// 	}
		
// 	if(j == 0)
// 	{
// 		rrb(va);
// 		push(va->a,va->final[top],va);
// 	}

// 	if (j == top)
// 	{
// 			va->index_stack += 1;
// 		push(va->a,va->final[top],va);
// 	}
	
// 	va->new = malloc(sizeof(int) * va->index_stack_final - 1);
// 	va->index_stack_final -= 1;
// 	j = va->index_stack_final;

// 	while (j >= 0 )
// 	{
// 		va->new[k] = va->final[j];
// 		k++;
// 		j--;
// 	}

// 	while (k > 0)
// 	{
// 		va->final[j] = va->new[k];
// 		k--;
// 		j++;
// 	}
// 	if (j == 1)
// 	{
// 		va->index_stack += 1;
// 		push(va->a,va->final[0],va);
// 	}
// 	printf("i m j = %d",j);
// }
