/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:05:28 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/02 15:02:44 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_putchar(char c)
{
	write(1,&c,1);
}

void	putstr(char *c)
{
	int	i;

	i = 0;

	while (c[i])
	{
		ft_putchar(c[i++]);
	}
	
}

long long	ft_atoi(const char *str,t_stack *va, char **tmp)
{
	int	i;
	int	c;
	int	res;
	
	i = 0;
	c = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			c *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] && (str[i] < '0' || str[i] > '9'))
	{
		putstr("Error\n");
		free(va->a);
		free(va->b);
		free(tmp);
		exit(0);
	}
	return (res * c);
}


void sb_swap(t_stack *va)
{
    int	a;
    int	b;

    a = 0;
    b = 0;
    if(va->index_stack_temp <= 0)
    exit (0);
    a = va->b[va->index_stack_temp];
    b = va->b[va->index_stack_temp - 1];
    va->b[va->index_stack_temp - 1] = a;
    va->b[va->index_stack_temp] = b;

}

void rrr(t_stack *va)
{
	rra(va);
	rrb(va);
}