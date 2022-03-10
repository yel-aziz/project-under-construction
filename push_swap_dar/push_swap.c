/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:58:53 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/10 16:21:06 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_table(int *t,int i)
{
	int j = 0;
	while (j < i )
	{
		printf("| %d |",t[j]);
		j++;
	}
}

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
	va.index_stack = index_stack(k);
	// va.index_stack_temp = va.index_stack;
	va.moyen_stack = (k /10) + 20;
	indexing(&va);
	printf("temp index =%d\n",va.index_stack_temp);
	printf("index a = %d\n",va.index_stack);
	sort_index(&va);	
	find_big(&va);
	find_big(&va);


}