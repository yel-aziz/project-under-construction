/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:59:08 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/31 14:09:28 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void rb(t_stack *va)
{
	int *temp;
	int	i;

	i = 0;
	temp = malloc(sizeof(int) * (va->index_stack_temp + 1));
	
	while (va->index_stack_temp >= 0)
	{
		temp[i] = va->b[va->index_stack_temp];
		i++;
		va->index_stack_temp--;
	}
	va->b[0] = temp[0];
	va->index_stack_temp += 2;
	i--;
	while (i > 0)
	{
		va->b[va->index_stack_temp++] = temp[i--];
	}
	va->index_stack_temp--;
	free(temp);
}

void pa(int *a, int b, t_stack *va)
{
	va->index_stack += 1;
	a[va->index_stack] = b;
}

void pb(int *b, int a, t_stack *va)
{
	va->index_stack_temp += 1;
	b[va->index_stack_temp] = a;
}

void rr(t_stack *va)
{
	ra(va);
	rb(va);
}

