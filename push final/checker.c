/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:04:16 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/19 20:42:44 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void ft_checker(t_stack *va)
{
	int i;
	int	j;

	i = 0;
	j = 0;

	while (va->a[i])
	{
		j = i + 1;
		while (va->a[j])
		{
			if(va->a[i] == va->a[j])
			{
				putstr("EROOR\n");
				exit(1);
			}
			j++;
		}
		i++;
	}

}