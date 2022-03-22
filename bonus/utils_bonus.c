/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:05:28 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/03/22 17:44:48 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*get_next_line(int fd)
{
	char	save[999999];
	char	buff[1];
	char	*line;
	int		i;

	i = 0;
	if (fd < 0)
		return (NULL);
	save[i] = '\0';
	while (read(fd, buff, 1) == 1)
	{
		if(buff[0] != '\n')
			save[i] = buff[0];
		save[i + 1] = '\0';
		if (buff[0] == '\n')
			break ;
		i++;
	}
	if (save[0] == '\0')
		return (NULL);
	line = malloc(i + 1);
	i = 0;
	while (save[i])
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

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

