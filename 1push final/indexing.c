/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:45:36 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/23 16:33:09 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void indexing(t_stack *va)
{
	
	int	i;
	int	j;
	int	k;
	int	cnt;
	int	*tmp;

	tmp = malloc(sizeof(int) * va->index_stack + 1);
	i = 0;
	k = 0;
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
		tmp[i] = cnt;
		cnt = 0;
		i++;
	}

	  i = i -1;
	while (i >= 0)
	{
		va->a[k++] = tmp[i--];
	}
}

void sort_index(t_stack *va)
{
	int	n;
	int cnt;

	n = 1;
	cnt = 0;
	va->index_stack_temp = -1;
	
	while (va->index_stack >= 0)
	{
		if(va->a[va->index_stack] < (va->moyen_stack * n))
		{
			push_b(va->b,va->a[va->index_stack],va);
			va->index_stack--;
			cnt++;
		}

		else
		{
			ra(va);
		}
		if(cnt == (va->moyen_stack * n))
		{
			n++;
		}
	}
		
}