/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:28:30 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/01 23:33:19 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_small_helper(t_stack *va, int min, int j)
{
	if (va->a[va->index_stack] > va->a[va->index_stack - 1]
		&& va->a[va->index_stack - 1] > va->a[va->index_stack - 2])
	{
		ra(va);
		sa(va);
	}
	if (va->a[va->index_stack - 2] == j && va->a[va->index_stack - 1] == min
		&& va->a[va->index_stack - 1] < va->a[va->index_stack]
		&& va->a[va->index_stack] < va->a[va->index_stack - 2])
	{
		sa(va);
	}
	else if (va->a[va->index_stack] == min && va->a[va->index_stack - 1] == j
		&& va->a[0] < va->a[va->index_stack - 1]
		&& va->a[0] > va->a[va->index_stack])
	{
		sa(va);
		ra(va);
	}	
}

void	ft_helper(t_stack *va, int j, int min)
{
	if (va->a[0] == min && va->a[1] == j && va->a[va->index_stack] < va->a[1]
		&& va->a[va->index_stack - 1] > va->a[0])
	{
		sa(va);
		ra(va);
		sa(va);
	}
	if (va->a[va->index_stack] > va->a[va->index_stack - 1]
		&& va->a[va->index_stack - 1] < va->a[va->index_stack - 2]
		&& va->a[va->index_stack] > va->a[va->index_stack - 2])
	{
		ra(va);
	}
}

void	ft_small(t_stack *va)
{
	int	i;
	int	j;
	int	min;

	i = va->index_stack;
	j = va->a[va->index_stack];
	min = va->a[va->index_stack];
	while (i >= 0)
	{
		if (va->a[i] > j)
			j = va->a[i];
		i--;
	}
	i = va->index_stack;
	while (i >= 0)
	{
		if (va->a[i] < min)
			min = va->a[i];
		i--;
	}
	ft_small_helper(va, min, j);
	ft_helper(va, j, min);
}

int	countword(char const *s, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (*s && *s == c)
		s++;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c) || s[i + 1] == '\0')
			count++;
		i++;
	}
	return (count);
}

int	lenword(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}
