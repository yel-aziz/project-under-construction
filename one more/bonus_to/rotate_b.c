/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:17:42 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/04 00:35:41 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_stack *va)
{	
	int	*temp;
	int	i;

	i = 0;
	if (va->index_stack > 0)
	{
		temp = malloc(sizeof(int) * va->index_stack + 1);
		if (!temp)
			exit(0);
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
		free(temp);
		va->index_stack--;
	}
}

void	rb(t_stack *va)
{
	int	*temp;
	int	i;

	i = 0;
	if (va->index_stack_temp > 0)
	{
		temp = malloc(sizeof(int) * (va->index_stack_temp) + 1);
		if (! temp)
			exit(0);
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
}

void	rra(t_stack *va)
{
	int	i;
	int	*temp;
	int	*first;

	i = 0;
	if (va->index_stack > 0)
	{
		first = malloc(sizeof(int) * 2);
		temp = malloc(sizeof(int) * va->index_stack + 1);
		if (!temp || !first)
			exit(0);
		while (va->index_stack >= 0)
		{
			temp[i] = va->a[va->index_stack--];
			i++;
		}
		va->index_stack += 1;
		first[0] = temp[i - 1];
		i = i - 2;
		while (i >= 0)
			va->a[va->index_stack++] = temp[i--];
		va->a[va->index_stack] = first[0];
		free(first);
		free(temp);
	}
}

void	rrb(t_stack *va)
{
	int	i;
	int	*temp;
	int	*first;

	i = 0;
	if (va->index_stack_temp > 0)
	{
		first = malloc(sizeof(int) * 2);
		temp = malloc(sizeof(int) * va->index_stack_temp + 1);
		if (!temp || !first)
			exit(0);
		while (va->index_stack_temp >= 0)
		{
			temp[i] = va->b[va->index_stack_temp--];
			i++;
		}
		va->index_stack_temp += 1;
		first[0] = temp[i - 1];
		i = i - 2;
		while (i >= 0)
			va->b[va->index_stack_temp++] = temp[i--];
		va->b[va->index_stack_temp] = first[0];
		free(first);
		free(temp);
	}
}
