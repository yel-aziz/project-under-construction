/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:12:06 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/18 03:28:11 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void ft_checking(int c, int *tab)
{
    if(c < 0)
    {
        free(tab);
        printf("\nnegative is here\n");
        exit(0);
    }
}

void    ft_sharing(int *tab, routine *rt)
{
    rt->number_of_philosophers = tab[0];
    rt->time_to_die = tab[1];
    rt->time_to_eat = tab[2];
    rt->time_to_sleep = tab[3];
    rt->number_of_times_each_philosopher_must_eat = tab[4];
}