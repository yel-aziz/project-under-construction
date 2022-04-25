/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:45:03 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/24 21:29:23 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct rot
{
   int  number_of_philosophers;
   int  time_to_die;
   int  time_to_eat;
   int  time_to_sleep;
   int  number_of_times_each_philosopher_must_eat;
}routine;

typedef struct philosopher
{
    pthread_mutex_t *mtx;
    int             id;
    pthread_mutex_t left_fork;
    pthread_mutex_t right_fork;
    routine *rot;
}thread;

int     ft_atoi(const char *str);
void    ft_checking(int c, int *tab);
void    ft_sharing(int *tab, routine *rt);
void    ft_parcing(char **av, int ac, routine *va);
void    ft_is_dead(routine *va);
#endif