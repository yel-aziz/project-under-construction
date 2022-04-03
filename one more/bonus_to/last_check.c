/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:04:57 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/03 15:14:06 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void last_check(t_stack *va)
{
	if(is_sorted(va) == 1 || va->index_stack_temp != -1)
	{
		ft_putstr("KO\n");
	}
	else
	ft_putstr("OK\n");
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