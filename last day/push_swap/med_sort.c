/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:27:10 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/30 20:45:47 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_brain(t_stack *va, int s, int j)
{
	if (s < (va->index_stack / 2))
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
}

int	ft_med_helper(t_stack *va, int j, int s)
{
	while (s <= va->index_stack)
	{
		if (va->a[s] == j)
			break ;
		s++;
	}
	return (s);
}

void	pusher(t_stack *va)
{
	ft_small(va);
	push(va->a, va->b[va->index_stack_temp], va);
	push(va->a, va->b[va->index_stack_temp - 1], va);
}

void	med_sort(t_stack *va)
{
	int	i;
	int	j;
	int	s;
	int	action;

	i = va->index_stack;
	action = 2;
	while (action > 0)
	{
		i = va->index_stack;
		j = va->a[va->index_stack];
		while (i >= 0)
		{
			if (va->a[i] < j)
				j = va->a[i];
			i--;
		}
		s = 0;
		s = ft_med_helper(va, j, s);
		ft_brain(va, s, j);
		push_b(va->b, va->a[va->index_stack], va);
		va->index_stack--;
		action--;
	}
	pusher(va);
}
