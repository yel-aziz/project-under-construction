/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:54:32 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/03 15:36:28 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void ft_action(t_stack *va, char *gnt)
{
	if (ft_strcmp(gnt,"rb\n") == 0)
		rb(va);
	else if (ft_strcmp(gnt,"ra\n") == 0)
		ra(va);
	else if (ft_strcmp(gnt,"rr\n") == 0)
	rr(va);
	else if (ft_strcmp(gnt,"pb\n") == 0)
	{
		pb(va->b,va->a[va->index_stack],va);
		va->index_stack--;
	}
	else if (ft_strcmp(gnt,"pa\n") == 0)
	{
		pa(va->a,va->b[va->index_stack_temp],va);
		va->index_stack_temp--;
	}
	else if (ft_strcmp(gnt,"rra\n") == 0)
		rra(va);
	else if (ft_strcmp(gnt,"rrb\n") == 0)
		rrb(va);
	else if (ft_strcmp(gnt,"rrr\n") == 0)
	rrr(va);
	else if (ft_strcmp(gnt,"sa\n") == 0)
	sa(va);
	else if (ft_strcmp(gnt,"sb\n") == 0)
	sb(va);
	else
	{
		ft_putstr("Eroor\n");
		exit(0);
	}
}

void print_table(int *tab, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		printf("%d\n",tab[i++]);
	}

}

void	ft_checker(t_stack *va)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < va->index_stack)
	{
		j = i + 1;
		while (j <= va->index_stack)
		{
			if (va->a[i] == va->a[j])
			{
				ft_putstr("Error\n");
				free(va->a);
				free(va->b);
				exit(0);
			}
			j++;
		}
		i++;
	}
}