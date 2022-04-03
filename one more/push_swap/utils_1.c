/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:35:17 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/03 15:29:44 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

long long int	ft_atoi(const char *str, t_stack *va, char **tmp)
{
	int				i;
	int				c;
	long long int	res;

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
		ft_exit(va, tmp);
	return (res * c);
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

void	sa(t_stack *va)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	putstr("sa\n");
	a = va->a[va->index_stack];
	b = va->a[va->index_stack - 1];
	va->a[va->index_stack - 1] = a;
	va->a[va->index_stack] = b;
}

void	ft_int(t_stack *va, long long n, char **tmp)
{
	if (n > 2147483647 || n < -2147483648)
	{
		putstr("Eroor\n");
		free_split(tmp);
		free(va->a);
		free(va->b);
		exit (0);
	}
}
