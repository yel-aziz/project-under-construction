/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_folder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:12:10 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/01 23:31:14 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_stack(int len_argument)
{
	int	index;

	index = len_argument - 1;
	return (index);
}

void	ft_free(t_stack *va)
{
	free(va->a);
	free(va->b);
}

void	ft_main(t_stack *va, int k, int l, char **tmp)
{
	va->index_stack_temp = -1;
	va->index_stack = index_stack(k);
	va->moyen_stack = (k / 10) + 8;
	ft_checker(va, tmp);
	indexing(va);
	l = checkme(va);
	if (l == 1)
	{
		ft_free(va);
		exit(2);
	}
	if (va->index_stack == 2)
		ft_small(va);
	else if (va->index_stack == 4)
		med_sort(va);
	else
	{
		sort_index(va);
		ft_sort(va);
	}
	free(va->a);
	free(va->b);
}

void	ft_maloc(t_stack *va, int i, char **tmp)
{
	va->a = (int *)malloc(sizeof(int) * i);
	va->b = (int *)malloc(sizeof(int) * i);
	if (!va->a || !va->b)
	{
		free_split(tmp);
		ft_free(va);
		exit(0);
	}
}

int	ft_arrlen(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		i++;
	return (i);
}
