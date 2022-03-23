/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:35:42 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/23 22:43:47 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>

typedef	struct s_stack
{
	int index_stack;
	int index_stack_temp;
	int index_stack_final;
	int *a;
	int *b;
	int	*final;
	int	*new;
	int	moyen_stack;
}t_stack;

void	ft_putchar(char c);
int		ft_atoi(const char *str);
void	push(int *a, int b, t_stack *va);
void	push_b(int *b, int a, t_stack *va);
void	ra(t_stack *va);
void	rb(t_stack *va);
void	rr(t_stack *v);
void	rra(t_stack *va);
void	rrb(t_stack *va);
void	rrr(t_stack *va);
void	indexing(t_stack *va);
void	push_final(int *final, int a, t_stack *va);
void	sort_index(t_stack *va);
void	find_big(t_stack *va);
void	sb_swap(t_stack *va);
void	ft_sort(t_stack *va);
void	push_bb(int *b, int a, t_stack *va);
void	ft_checker(t_stack *va);
void	putstr(char *c);
int		checkme(t_stack *va);
void	print_table(int	*a,int	k);
void	ft_small(t_stack *va);
void 	sa(t_stack *va);
void	med_sort(t_stack *va);
#endif