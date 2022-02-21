/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:58:53 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/02/21 22:18:16 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_stack(int len_argument)
{
	int	index;

	index = len_argument - 1;

	return (index);
}

int	*sa_swap(int *table, int index_stack)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if(index_stack <= 0)
		exit (0);
		a = table[index_stack];
		b = table[index_stack - 1];
		table[index_stack - 1] = a;
		table[index_stack] = b;
		return (table);
}

void push(t_stack *a, int k)
{
	a->top++;
	a->items[a->top] = k;
}

int main(int ac, char **av )
{
	
}