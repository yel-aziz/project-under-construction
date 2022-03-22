/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkme.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:42:36 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/19 21:42:43 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int checkme(t_stack *va)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	
	while (i <= va->index_stack - 1)
	{
		j = i + 1;
		while (j <= va->index_stack)
		{
			if (va->a[i] < va->a[j])
			{
				j++;
			}
			else
			{
				return (0);
			}
		}	
		i++;

	}
	return(1);
}