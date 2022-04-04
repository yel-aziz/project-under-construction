/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:04:57 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/04 00:33:47 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	last_check(t_stack *va, int	*tmp)
{
	if (is_sorted(va) == 1 || va->index_stack_temp != -1)
	{
		free(va->a);
		free(va->b);
		free(tmp);
		ft_putstr("KO\n");
		exit(0);
	}
	else
	{
		free(va->a);
		free(va->b);
		free(tmp);
		ft_putstr("OK\n");
		exit(0);
	}	
}

void	sa(t_stack *va)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	a = va->a[va->index_stack];
	b = va->a[va->index_stack - 1];
	va->a[va->index_stack - 1] = a;
	va->a[va->index_stack] = b;
}

void	sb(t_stack *va)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	a = va->b[va->index_stack_temp];
	b = va->b[va->index_stack_temp - 1];
	va->b[va->index_stack_temp - 1] = a;
	va->b[va->index_stack_temp] = b;
}

void	ft_free_split(char **spl)
{
	int	i;

	i = 0;
	while (spl[i])
		free(spl[i++]);
	free(spl);
}

int	is_sorted(t_stack *va)
{
	int	i;
	int	j;

	i = 0;
	while (i < va->index_stack)
	{
		j = i +1;
		while (j <= va->index_stack)
		{
			if (va->a[i] > va->a[j])
			{
				j++;
			}
			else
				return (1);
		}
		i++;
	}
	return (0);
}
