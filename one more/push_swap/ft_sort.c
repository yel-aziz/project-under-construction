/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 23:31:26 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/01 23:29:26 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_helper(t_stack *va, int s, int action, int j)
{
	if (s <= action)
	{
		while (va->b[va->index_stack_temp] != j)
		{
			rrb(va);
		}
	}
	else
	{
		while (va->b[va->index_stack_temp] != j)
		{
			rb(va);
		}
	}
}

int	ft_finder(t_stack *va, int s, int j)
{
	while (s <= va->index_stack_temp)
	{
		if (va->b[s] == j)
			break ;
		s++;
	}
	return (s);
}

void	ft_sort(t_stack *va)
{
	int	i;
	int	j;
	int	s;
	int	action;

	i = va->index_stack_temp;
	j = va->index_stack_temp;
	while (va->index_stack_temp >= 0)
	{
		action = (va->index_stack_temp / 2);
		i = va->index_stack_temp;
		j = va->b[va->index_stack_temp];
		while (i >= 0)
		{
			if (va->b[i] > j)
				j = va->b[i];
			i--;
		}
		s = 0;
		s = ft_finder(va, s, j);
		ft_sort_helper(va, s, action, j);
		push(va->a, va->b[va->index_stack_temp], va);
		va->index_stack_temp--;
	}
}

char	*ft_strdup(const char *s1)
{
	char	*re;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	re = (char *)malloc((i + 1) * sizeof(char));
	if (!re)
		return (NULL);
	i = -1;
	while (s1[++i])
		re[i] = s1[i];
	re[i] = '\0';
	return (re);
}
