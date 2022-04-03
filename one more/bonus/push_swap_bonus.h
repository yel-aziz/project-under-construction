/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:10:59 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/02 15:01:49 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H




#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "get_next_line.h"


typedef struct va
{
	int	*a;
	int	*b;
	int	index_stack_temp;
	int	index_stack;
	
}t_stack;

void	ft_checker_bonus(char *p);
void	ft_putchar(char c);
void	putstr(char *c);
long long	ft_atoi(const char *str,t_stack *va, char **tmp);
void	ra(t_stack *va);
void	rb(t_stack *va);
void	rra(t_stack *va);
void	rrb(t_stack *va);
void	pb(int *b, int a, t_stack *va);
void	pa(int *a, int b, t_stack *va);
int		ft_strncmp(const char *s1, const char *s2);
void	sa_swap(t_stack *va);
void	sb_swap(t_stack *va);
void	ft_checker(t_stack *va);
void	rr(t_stack *va);
void	rrr(t_stack *va);
int	main_to_folder(t_stack *va, char *jo);
void	ft_parcing(t_stack *va, char **av);

#endif