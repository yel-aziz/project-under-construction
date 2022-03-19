/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:40:45 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/19 16:13:16 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void ra(t_stack *va)
{
	putstr("ra\n");
	int *temp;
	int	i;

	i = 0;
	temp = malloc(sizeof(int) * va->index_stack + 1);
	while (va->index_stack >= 0)
	{
		temp[i] = va->a[va->index_stack];
		i++;
		va->index_stack--;
	}
	va->a[0] = temp[0];
	va->index_stack += 2;
	i--;
	while (i > 0)
	{
		va->a[va->index_stack++] = temp[i--];
	}	
	va->index_stack--;
}

void rb(t_stack *va)
{
	putstr("rb\n");
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
}


void rra(t_stack *va)
{
	putstr("rra\n");
	int	i;
	int	*temp;
	int	*first;

	i = 0;
	first=malloc(1);
	temp = malloc(sizeof(int) * va->index_stack + 1);

	while (va->index_stack >= 0)
	{
		temp[i] = va->a[va->index_stack--];
		i++;
	}
	va->index_stack += 1;
	first[0] = temp[i - 1];
	i = i - 2;
	while (i >= 0)
	{
		va->a[va->index_stack++] = temp[i--];
	}
	va->a[va->index_stack] = first[0];	
}

void rrb(t_stack *va)
{
	putstr("rrb\n");
	
	int	i;
	int	*temp;
	int	*first;

	i = 0;
	first = malloc(1);
	temp = malloc(sizeof(int) * va->index_stack_temp + 1);

	while (va->index_stack_temp >= 0)
	{
		temp[i] = va->b[va->index_stack_temp--];
		i++;
	}
	va->index_stack_temp += 1;
	first[0] = temp[i - 1];
	i = i - 2;
	while (i >= 0)
	{
		va->b[va->index_stack_temp++] = temp[i--];
	}
	va->b[va->index_stack_temp] = first[0];	
}
