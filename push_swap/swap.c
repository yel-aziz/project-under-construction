/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:38:23 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/05 13:44:08 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void sa_swap(t_stack *va)
{
    int	a;
    int	b;

    a = 0;
    b = 0;
    if(va->index_stack <= 0)
    exit (0);
    a = va->a[va->index_stack];
    b = va->a[va->index_stack - 1];
    va->a[va->index_stack - 1] = a;
    va->a[va->index_stack] = b;

}