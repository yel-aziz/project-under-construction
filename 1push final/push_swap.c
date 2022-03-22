/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:03:27 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/22 21:01:04 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_stack(int len_argument)
{
	int	index;

	index = len_argument - 1;

	return (index);
}

int main(int ac, char **av)
{
	t_stack va;
	int	i;
	int	k;
	int	f;
	char *p;

	p = malloc(10);
	i = 1;
	k = 0;
	ac = 0;

	while (av[i])
	i++;

	va.a = malloc(sizeof(int) * i);
	va.b = malloc(sizeof(int) * i);
	va.final = malloc(sizeof(int) * i);
	i = 1;
	while (av[i])
	{
		va.a[k++] = ft_atoi(av[i++]);
	}

	
	if(k == 1)
	{
		exit(0);
	}
	va.index_stack_temp = -1;
	va.index_stack_final = -1;
	va.index_stack = index_stack(k);
	va.moyen_stack = (k / 10) + 8;
	 f = checkme(&va);
	 ft_checker(&va);
	 if(f == 0)
	 {
		indexing(&va);
		va.index_stack = -1;
		sort_index(&va);
		ft_sort(&va);
	 }

}