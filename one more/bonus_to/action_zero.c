/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:54:32 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/04 00:32:01 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_action_too(t_stack *va, char *gnt, int *tmp)
{
	if (ft_strcmp(gnt, "rra\n") == 0)
		rra(va);
	else if (ft_strcmp(gnt, "rrb\n") == 0)
		rrb(va);
	else if (ft_strcmp(gnt, "rrr\n") == 0)
		rrr(va);
	else if (ft_strcmp(gnt, "sa\n") == 0)
		sa(va);
	else if (ft_strcmp(gnt, "sb\n") == 0)
		sb(va);
	else if (ft_strcmp(gnt, "ss\n") == 0)
		ss(va);
	else
	{
		ft_putstr("Eroor\n");
		free(tmp);
		free(va->a);
		free(va->b);
		exit(0);
	}
}

void	ft_action(t_stack *va, char *gnt, int *tmp)
{
	if (ft_strcmp(gnt, "rb\n") == 0)
		rb(va);
	else if (ft_strcmp(gnt, "ra\n") == 0)
		ra(va);
	else if (ft_strcmp(gnt, "rr\n") == 0)
		rr(va);
	else if (ft_strcmp(gnt, "pb\n") == 0)
	{
		pb(va->b, va->a[va->index_stack], va);
		va->index_stack--;
	}
	else if (ft_strcmp(gnt, "pa\n") == 0)
	{
		pa(va->a, va->b[va->index_stack_temp], va);
		va->index_stack_temp--;
	}
	else
		ft_action_too(va, gnt, tmp);
}

void	ft_checker(t_stack *va, int	*tmp)
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
				free(tmp);
				free(va->a);
				free(va->b);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	ss(t_stack *va)
{
	sa(va);
	sb(va);
}
