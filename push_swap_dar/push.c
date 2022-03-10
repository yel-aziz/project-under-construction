/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:40:00 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/10 18:44:53 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void push(int *a, int b, t_stack *va)
{
	va->index_stack += 1;
	a[va->index_stack + 1] = b;
}

void push_b(int *b, int a, t_stack *va)
{

	va->index_stack_temp += 1;
	b[va->index_stack_temp] = a;
}


void push_final(int *final, int a, t_stack *va)
{
	final[va->index_stack_final + 1] = a;
	va->index_stack_final += 1;
}