/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:40:00 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/13 22:26:47 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void push(int *a, int b, t_stack *va)
{
	printf("pa\n");
	va->index_stack += 1;
	a[va->index_stack] = b;
}

void push_b(int *b, int a, t_stack *va)
{
	printf("pb\n");
	va->index_stack_temp += 1;
	b[va->index_stack_temp] = a;
}


void push_final(int *final, int a, t_stack *va)
{
	printf("pa\n");
	final[va->index_stack_final + 1] = a;
	va->index_stack_final += 1;
}