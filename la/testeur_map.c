/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeur_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:05:47 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/02/08 19:55:57 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	p_check(char **p, int n, int m)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	j = 0;
	t = 0;
	while (p[i] && i < n)
	{
		j = 0;
		while (j < m)
		{
			if (p[i][j] == 'P' || p[i][j] == 'C' || p[i][j] == 'E')
			{
				t += 1;
			}
			j++;
		}
		i++;
	}
	if (t < 3)
		return (0);
	else
		return (1);
}

void	c_check(char **p, int n, int m, t_map *cl)
{
	int		i;
	int		j;
	int		t;

	i = 0;
	j = 0;
	t = 0;
	cl->c = 0;
	while (p[i] && i < n)
	{
		j = 0;
		while (j < m)
		{
			if (p[i][j] == 'C')
			{
				cl->c++;
			}
			j++;
		}
		i++;
	}
}

int	allcaracter_check(char **p, int n, int m, char c)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	j = 0;
	t = 0;
	while (p[i] && i < n)
	{
		j = 0;
		while (j < m)
		{
			if (p[i][j] == c)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_othercarecter(char **p, t_map *test)
{
	while (p[test->q] && test->q < test->n)
	{
		test->w = 0;
		while (test->w < test->m)
		{
			if (p[test->q][test->w] != '0' && p[test->q][test->w] != '1'
					&& p[test->q][test->w] != 'P'
					&& p[test->q][test->w] != 'C' && p[test->q][test->w] != 'E')
			{
				return (0);
			}
			test->w++;
		}
		test->q++;
	}
	return (1);
}

int	testeur_map(char **p, t_map *test)
{
	int	y;

	y = 0;
	initialisation(test);
	if (check_lines (p, test) == 0)
		return (0);
	test->n = 0;
	if (walltest(p, test) == 0)
		return (0);
	if (check_othercarecter (p, test) == 0)
		return (0);
	test->t = p_check(p, test->n, test->m);
	c_check(p, test->n, test->m, test);
	y += allcaracter_check(p, test->n, test->m, 'C');
	y += allcaracter_check(p, test->n, test->m, 'P');
	y += allcaracter_check(p, test->n, test->m, 'E');
	if (y < 3)
		return (0);
	return (1);
}
