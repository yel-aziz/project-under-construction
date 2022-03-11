/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:58:53 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/11 20:08:14 by yel-aziz         ###   ########.fr       */
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
	va.index_stack_temp = -1;
	va.index_stack_final = -1;
	va.index_stack = index_stack(k);
	va.moyen_stack = (k /10) + 20;
	
	printf("index stack a = %d\n ",va.index_stack);
	printf("index stack b = %d\n ",va.index_stack_temp);
	printf("index stack final = %d\n ",va.index_stack_final);
	printf("stack a = ");
	print_table(va.a,va.index_stack + 1);
	printf("\nstack b = ");
	print_table(va.b,va.index_stack_temp + 1);
	printf("\nstack final = ");
	print_table(va.final,va.index_stack_final + 1);
	printf("\nstack new = ");
	print_table(va.new,va.index_stack_temp + 1);
	printf("\n|||||||after indexing|||||\n");
	indexing(&va);
	sort_index(&va);
	
	while (va.index_stack_final > 0)
	{
		find_big(&va);
	}
	
	
	printf("index stack a = %d\n ",va.index_stack);
	printf("index stack b = %d\n ",va.index_stack_temp);
	printf("index stack final = %d\n ",va.index_stack_final);
	printf("stack a = ");
	print_table(va.a,3);
	printf("\nstack b = ");
	print_table(va.b,va.index_stack_temp+1);
	printf("\nstack final = ");
	print_table(va.final,va.index_stack_final + 1);
	
	// printf("\nstack new = ");
	// print_table(va.new,va.index_stack_temp + 1);



}