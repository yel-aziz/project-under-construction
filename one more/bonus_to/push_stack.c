/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:19:03 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/04 00:13:32 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(int *a, int b, t_stack *va)
{
	va->index_stack += 1;
	a[va->index_stack] = b;
}

void	pb(int *b, int a, t_stack *va)
{
	va->index_stack_temp += 1;
	b[va->index_stack_temp] = a;
}

long long	ft_atoi(const char *str)
{
	int			i;
	long long	c;
	long long	res;

	i = 0;
	c = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			c *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	if (str[i] && (str[i] < '0' || str[i] > '9'))
	{
		ft_putstr("Eroor\n");
		exit(0);
	}
	return (res * c);
}

void	rr(t_stack *va)
{
	ra(va);
	rb(va);
}

void	rrr(t_stack *va)
{
	rra(va);
	rrb(va);
}
