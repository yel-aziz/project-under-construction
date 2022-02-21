/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:35:42 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/02/21 22:16:33 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>

typedef	struct s_stack
{
	int top;
	int capacity;
	int	*items;
}t_stack;

void	ft_putchar(char c);
int		ft_atoi(const char *str);
int		*push_a(int *b, int index_stack_b);



#endif