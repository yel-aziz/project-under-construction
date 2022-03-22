/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:02:54 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/22 20:59:02 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void ft_todo(char *p, t_stack *va)
{
	
	if(strcmp(p,"rb") == 0)
	rb(va);
	else if(strcmp(p,"ra") == 0)
	ra(va);
	if(strcmp(p,"pa") == 0)
	{
	pa(va->a,va->b[va->index_stack_temp], va);
	va->index_stack_temp -= 1;
	}
	else if(strcmp(p,"pb") == 0)
	{
		pb(va->b,va->a[va->index_stack], va);
		va->index_stack -= 1;
	}
	
	if(strcmp(p,"rra") == 0)
	rra(va);
	else  if(strcmp(p,"rrb") == 0)
	rrb(va);
	
}

void	print_table(int	*a,int	k)
{
	int	i;

	i = 0;

	while (i <= k)
	{
		printf("| %d | ",a[i]);
		i++;
	}
	
}

int main(int ac, char **av)
{
	t_stack	va;
	char	*c;
	int		k;
	int		i;

	ac = 0;
	i = 1;
	k = 0;
	
	while (av[i])
		i++;
	va.a = malloc(sizeof(int) * i + 1);
	va.b = malloc(sizeof(int) * i + 1);
	i = 1;
	while (av[i])
	{
		va.a[k++] = ft_atoi(av[i++]);
	}
	va.index_stack = (k - 1);
	va.index_stack_temp = -1;
	print_table(va.a,va.index_stack);
	printf("\n");
	
	
	c = "\0";
	while (c != NULL)
	{		
		ft_todo(c, &va);
		c = get_next_line(0);
	}
	print_table(va.b,va.index_stack_temp);
	
	
}