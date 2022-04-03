/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:45:36 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/01 23:29:54 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_tab(t_stack *va, int i, int *tmp, int k)
{
	while (i >= 0)
	{
		va->a[k++] = tmp[i--];
	}
	free(tmp);
}

void	indexing(t_stack *va)
{
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * (va->index_stack + 1));
	if (!tmp)
		ft_free(va);
	va->i = 0;
	va->k = 0;
	va->j = 0;
	va->cnt = 0;
	while (va->i <= va->index_stack)
	{
		va->j = 0;
		while (va->j <= va->index_stack)
		{
			if (va->i != va->j && va->a[va->i] > va->a[va->j])
				va->cnt++;
			va->j++;
		}
		tmp[va->i] = va->cnt;
		va->cnt = 0;
		va->i++;
	}
	va->i = va->i - 1;
	rev_tab(va, va->i, tmp, va->k);
}

void	sort_index(t_stack *va)
{
	int	n;
	int	cnt;

	n = 1;
	cnt = 0;
	while (va->index_stack >= 0)
	{
		if (va->a[va->index_stack] < (va->moyen_stack * n))
		{
			push_b(va->b, va->a[va->index_stack], va);
			va->index_stack--;
			cnt++;
		}
		else
		{
			ra(va);
		}
		if (cnt == (va->moyen_stack * n))
		{
			n++;
		}
	}
}
