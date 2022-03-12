/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:38:23 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/12 14:15:56 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void sb_swap(t_stack *va)
{
    int	a;
    int	b;

    a = 0;
    b = 0;
    // if(va->index_stack_temp <= 0)
    // exit (0);
    a = va->b[va->index_stack_temp];
    b = va->b[va->index_stack_temp - 1];
    va->b[va->index_stack_temp - 1] = a;
    va->b[va->index_stack_temp] = b;

}