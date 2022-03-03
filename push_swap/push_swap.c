/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:58:53 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/03 16:59:38 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_table(int *t,int i)
{
	int j = 0;
	while (j < i )
	{
		printf("%d",t[j]);
		j++;
	}
}
int	index_stack(int len_argument)
{
	int	index;

	index = len_argument - 1;

	return (index);
}

// int	*sa_swap(int *table)
// {
// 	int	a;
// 	int	b;
// 	t_stack va;

// 	a = 0;
// 	b = 0;
// 	if(va.index_stack <= 0)
// 		exit (0);
// 		a = table[va.index_stack];
// 		b = table[va.index_stack - 1];
// 		table[va.index_stack - 1] = a;
// 		table[va.index_stack] = b;
// 		return (table);
// }

// void push(int *a, int b, t_stack *va)
// {
// 	a[va->index_stack+1] = b;
// 	va->index_stack += 1;
// }

void push_b(int *b, int a, t_stack *va)
{
	b[va->index_stack_temp + 1] = a;
	va->index_stack_temp += 1;
}

void ra(t_stack *va)
{
	int *temp;
	int	i;

	i = 0;
	temp = malloc(sizeof(int) * va->index_stack);
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
}

void rb(t_stack *va)
{
	int *temp;
	int	i;

	i = 0;
	temp = malloc(sizeof(int) * va->index_stack_temp);
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
}

void	rr(t_stack *v)
{
	rb(v);
	ra(v);
}

void rra(t_stack *va)
{
	int	i;
	int	*temp;
	int	*first;

	i = 0;
	first=malloc(1);
	temp = malloc(sizeof(int) * va->index_stack);

	while (va->index_stack >= 0)
	{
		temp[i] = va->a[va->index_stack--];
		i++;
	}
	va->index_stack += 1;
	first[0] = temp[i - 1];
	i = i - 2;
	while (i >= 0)
	{
		va->a[va->index_stack++] = temp[i--];
	}
	va->a[va->index_stack] = first[0];	
}

void rrb(t_stack *va)
{
	int	i;
	int	*temp;
	int	*first;

	i = 0;
	first = malloc(1);
	temp = malloc(sizeof(int) * va->index_stack_temp);

	while (va->index_stack_temp >= 0)
	{
		temp[i] = va->b[va->index_stack_temp--];
		i++;
	}
	va->index_stack_temp += 1;
	first[0] = temp[i - 1];
	i = i - 2;
	while (i >= 0)
	{
		va->b[va->index_stack_temp++] = temp[i--];
	}
	va->b[va->index_stack_temp] = first[0];	
}
void	rrr(t_stack *va)
{
	rra(va);
	rra(va);
}

void indexing(t_stack *va)
{

	int	i;
	int	j;
	int	cnt;
	int	*a;

	i = 0;
	j = 0;
	cnt = 0;
	a = malloc(sizeof(int) * va->index_stack);
	while (i <= va->index_stack)
	{
		j = 0;
		while (j <= va->index_stack)
		{
			if (i != j && va->a[j] < va->a[i])
			{
				cnt++;
			}
			
			j++;
		}
		a[i] = cnt;
		cnt = 0;
		i++;
	}
		print_table(a,i);
}

void ft_sort(t_stack *va)
{
	va->index_stack_temp = -1;
	while (va->a[va->index_stack] >= 0)
	{
		printf("index frome sort = %d\n",va->index_stack);
		if (va->a[va->index_stack] < va->moyen_stack)
		{
			printf("watari9");
			printf("dakhelat\n");
			push_b(va->b,va->a[va->index_stack],va);
		}
		va->index_stack--;
	}
}
int main(int ac, char **av )
{
	t_stack variable;
	int i;
	int k;

	ac = 0;
	i = 1;
	// if (ac < 2)
	// return (0);

	while (av[i])
	i++;
	variable.a = malloc(sizeof(int) * i);
	variable.b = malloc(sizeof(int) * i);
	i = 1;
	k = 0;
	while (av[i])
	{
		variable.a[k++] = ft_atoi(av[i]);
		i++;
	}
	variable.index_stack = index_stack(k);
	indexing(&variable);
	// printf("index before =%d\n",variable.index_stack);
	// printf("index after =%d\n",variable.index_stack);
	// printf("table a=%d\n",variable.a[3]);
	variable.moyen_stack = ((k / 10) + 20);
	// printf("moyen stack =%d\n",variable.moyen_stack);
	// ft_sort(&variable);
	// printf("\n");
	// printf("table b = %d\n",variable.b[2]);
}