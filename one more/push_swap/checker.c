/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:04:16 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/01 22:47:25 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checker(t_stack *va, char **tmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < va->index_stack)
	{
		j = i + 1;
		while (j <= va->index_stack)
		{
			if (va->a[i] == va->a[j])
			{
				putstr("Error\n");
				free(tmp);
				free(va->a);
				free(va->b);
				exit(0);
			}
			j++;
		}
		i++;
	}
}
