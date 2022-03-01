/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:58:53 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/01 13:24:46 by yel-aziz         ###   ########.fr       */
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

// void push_b(int *b, int a, t_stack *va)
// {
// 	b[va->index_stack_temp+1] = a;
// 	va->index_stack_temp += 1;
// }

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
void	ft_sort(t_stack *va,int	b)
{
	int	j;

	j = va->index_stack_temp;
	while (j >= 0)
	{
		if (va->b[j] >= b)
		{
			if (j == va->index_stack_temp)
			{
				va->index_stack += 1;
				va->a[va->index_stack_temp] = va->b[j];
			}
			if (j < va->index_stack_temp)
			{
				if (j < (va->index_stack_temp / 2))
				{
					
						rrb(va);
						va->a[0] = va->b[j];
					
				}
				
			}
			
		}
		
		j--;
	}
	
}
int main(int ac, char **av )
{
	t_stack variable;
	int i;
	int k;
	int	b;
	int	j;
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
		variable.b[k++] = ft_atoi(av[i]);
		i++;
	}
	variable.index_stack_temp = index_stack(k); 
	j = variable.index_stack_temp;
	b = 0;
	while (j >= 0)
	{
		b += variable.b[j];
		j--;
	}
	b = (b / k);
	variable.index_stack = 0;
	print_table(variable.b,variable.index_stack_temp+1);
	printf("\n");
	ft_sort(&variable,b);
	print_table(variable.b,variable.index_stack_temp+1);
	printf("\n");
	print_table(variable.a,1);
}