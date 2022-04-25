/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 00:10:56 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/25 01:41:02 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void *ft_routine(void *p)
{
    thread *philo;
    int eating;
    int sleeping;
    int reminder;
    int modu;

    philo = (thread *)p;
     modu = (philo->id % philo->rot->number_of_philosophers);
    reminder = philo->rot->time_to_die;
        eating = philo->rot->time_to_eat;
        sleeping = philo->rot->time_to_sleep;
        
        pthread_mutex_lock(&philo->mtx[philo->id + 1]);
        printf("\nphilo id %d hase take afork\n",philo->id);
        pthread_mutex_lock(&philo->mtx[modu]);
        printf("\nphilo id %d hase take the seconde fork\n",philo->id);
        printf("\nphilo id %d is eating\n",philo->id);
        usleep(eating);
        pthread_mutex_unlock(&philo->mtx[philo->id + 1]);
        pthread_mutex_unlock(&philo->mtx[modu]);
        printf("\nphilo id %d is sleeping\n",philo->id);
        usleep(sleeping);
        
    return(p);
}

int main(int ac, char **av)
{
    routine va;
    thread  fork;
    int     n;
    int     i;

    fork.id = 0;
    i = 0;
    ft_parcing(av, ac, &va);
    n = va.number_of_philosophers;
     pthread_t th[n];
    fork.mtx = malloc(sizeof(pthread_mutex_t) * va.number_of_philosophers);
    fork.rot = &va;
    while (i < va.number_of_philosophers)
    {
        pthread_mutex_init(&fork.mtx[i], NULL);
        i++;
    }
    i = 0;
    while (i < va.number_of_philosophers)
    {
        pthread_create(&th[i], NULL, &ft_routine, &fork);
        fork.id++;
        sleep(1);
        i++;
    }
}