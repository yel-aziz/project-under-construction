/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:58:53 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/13 22:23:58 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_table(int *t,int i)
{
	int j = 0;
	while (j <= i )
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
	va.index_stack_temp = -1;
	va.index_stack_final = -1;
	va.index_stack = index_stack(k);
	va.moyen_stack = (k / 10) + 5;

	indexing(&va);
	va.index_stack = -1;
	sort_index(&va);
	ft_sort(&va);
	// printf("b from indexing = ");
	// print_table(va.b,va.index_stack_temp);
	// printf("\nindex b =%d",va.index_stack_temp);
	// printf("\na from indexing = ");
	// print_table(va.a,va.index_stack);
	// printf("\nindex a =%d",va.index_stack);
	// sort_index(&va);
	// printf("\nfinal from sort_index = ");
	// print_table(va.final,va.index_stack_final);
	// printf("\nb from sort_index = ");
	// print_table(va.b,va.index_stack_temp);
	// printf("\nindex b = %d",va.index_stack_temp);
	// ft_sort(&va);
	printf("\na from ft_sort = ");
	print_table(va.a,va.index_stack);
	


	

	

}