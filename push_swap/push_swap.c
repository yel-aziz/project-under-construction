/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:58:53 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/02/16 22:23:25 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av )
{

	int *tmp_1;
	ac = 0;
	int i = 1;
	int k = 0;

	while (av[i])
	{
		i++;
	}
	tmp_1 = malloc(i *sizeof(int));
	i = 1;
	while (av[i])
	{
		tmp_1[k++] = ft_atoi(av[i]);
		i++;
	}
	k =0;
	while (k < i - 1)
	printf("%d\n",tmp_1[k++]);

	
	
}