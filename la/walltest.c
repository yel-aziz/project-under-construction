/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walltest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:27:34 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/02/08 19:54:37 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	walltest(char **p, t_map *test)
{
	while (p[test->n] && p[test->n][0] == '1')
	{
		test->n++;
	}
	while (p[test->k] && p[test->k][test->j - 1] == '1')
	{
		test->k++;
	}
	if (test->n != test->k)
	{
		return (0);
	}
	while (test->l != test->k)
	{
		while (p[test->l][test->m])
		{
			test->m++;
		}
		test->l++;
	}
	if (test->m != test->i && test->m != test->j)
	{
		return (0);
	}
	return (1);
}

void	initialisation(t_map *test)
{
	test->i = 0;
	test->j = 0;
	test->j = 0;
	test->k = 0;
	test->l = 0;
	test->m = 0;
	test->n = 0;
	test->q = 0;
	test->q = 0;
	test->t = 0;
}

int	check_lines(char **p, t_map *test)
{
	while (p[test->n])
	{
		test->n++;
	}
	while (p[0][test->i] == '1')
	{
		test->i++;
	}
	while (p[test->n - 1][test->j] == '1')
	{
		test->j++;
	}
	if (test->i != test->j)
	{
		return (0);
	}
	return (1);
}
