/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis_to.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:45:37 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/31 14:10:16 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s1[i] && (unsigned char)s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

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

void ra(t_stack *va)
{
	int *temp;
	int	i;

	i = 0;
	
	temp = malloc(sizeof(int) * va->index_stack );
	while (va->index_stack >= 0)
	{
		temp[i] = va->a[va->index_stack];
		i++;
		va->index_stack--;
	}
	va->a[0] = temp[0];
	va->index_stack += 2;
	i--;
	while (i > 0)
	{
		va->a[va->index_stack++] = temp[i--];
	}	
	va->index_stack--;
	free(temp);
}

void rra(t_stack *va)
{
	int	i;
	int	*temp;
	int	*first;

	i = 0;
	first=malloc(1);
	temp = malloc(sizeof(int) * va->index_stack + 1);

	while (va->index_stack >= 0)
	{
		temp[i] = va->a[va->index_stack--];
		i++;
	}
	va->index_stack += 1;
	first[0] = temp[i - 1];
	i = i - 2;
	while (i >= 0)
	{
		va->a[va->index_stack++] = temp[i--];
	}
	va->a[va->index_stack] = first[0];
	free(temp);
	free(first);
}

void rrb(t_stack *va)
{
	int	i;
	int	*temp;
	int	*first;

	i = 0;
	first = malloc(1);
	temp = malloc(sizeof(int) * va->index_stack_temp + 1);

	while (va->index_stack_temp >= 0)
	{
		temp[i] = va->b[va->index_stack_temp--];
		i++;
	}
	va->index_stack_temp += 1;
	first[0] = temp[i - 1];
	i = i - 2;
	while (i >= 0)
	{
		va->b[va->index_stack_temp++] = temp[i--];
	}
	va->b[va->index_stack_temp] = first[0];
	free(temp);
	free(first);
}
