/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:40:00 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/01 23:31:49 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	push(int *a, int b, t_stack *va)
{
	putstr("pa\n");
	va->index_stack += 1;
	a[va->index_stack] = b;
}

void	push_b(int *b, int a, t_stack *va)
{
	putstr("pb\n");
	va->index_stack_temp += 1;
	b[va->index_stack_temp] = a;
}

void	ft_exit(t_stack *va, char **tmp)
{
	putstr("Error\n");
	ft_free(va);
	free_split(tmp);
	exit(0);
}

int	ft_strlen(const char *p)
{
	size_t	i;

	i = 0;
	while (p[i] != '\0')
		i++;
	return (i);
}
