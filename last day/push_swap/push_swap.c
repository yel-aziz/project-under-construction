/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:03:27 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/01 21:33:46 by yel-aziz         ###   ########.fr       */
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
		free(tmp);
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

void	ft_maloc(t_stack *va, int i)
{
	va->a = (int *)malloc(sizeof(int) * i);
	va->b = (int *)malloc(sizeof(int) * i);
	if (!va->a || !va->b)
		exit(0);
}

int ft_arrlen(char **tmp) {
	int i;

	i = 0;
	while (tmp[i])
		i++;
	return i;
}

int	main(int ac, char **av)
{
	t_stack			va;
	int				i;
	int				k;
	long long int	n;
	int				l;
	int				j;
	char			**tmp;
	char			*jo;
	ac = 0;
	i = 1;
	k = 0;
	l = 0;
	j = 0;
	n = 0;

	tmp = NULL;
	while (av[i])
		i++;
	i -= 1;
	jo = ft_strdup(" ");
	j = 1;
	while (j <= i)
	{
		jo = ft_strjoin(jo,av[j]);
		jo = ft_strjoin(jo," ");
		j++;
	}
	tmp = ft_split(jo,' ');
	free(jo);
	ft_maloc(&va, ft_arrlen(tmp));
	i = 0;
	while (tmp[i])
	{
		n = ft_atoi(tmp[i++]);
		ft_int(&va, n);
		va.a[k++] = n;
	}
	free_split(tmp);
	ft_main(&va, k, l, tmp);
	return (0);
}	
