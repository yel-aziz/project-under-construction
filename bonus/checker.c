/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:05:52 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/21 23:53:35 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void ft_checker_bonus(char *p)
{
	if(strcmp(p,"rb") == 0)
	printf("\nkbida kayn\n");
}
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

int	ft_atoi(const char *str)
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
		exit(0);
	}
	return (res * c);
}



int main(int ac, char **av)
{
	char	*p;
	int		s;
	int		i;
	int		*a;
	int		k;

	i = 1;
	k = 0;

	while (av[i])
	{
		i++;
	}
	a = malloc(sizeof(int) * i);
	i = 1;
	while (av[i])
	{
		a[k++] = ft_atoi(av[i]);
		i++;
	}
	
	while ((s = read(0,p,2)) > 0)
	{
		p[s]= 0;
		ft_checker_bonus(p);
	}

}