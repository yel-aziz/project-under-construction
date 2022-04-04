/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:09:56 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/03 23:58:49 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strlen(const char *p)
{
	int	i;

	i = 0;
	if (!p)
		return (0);
	while (p[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char	*s1, char	*s2)
{
	int		i;
	int		j;
	char	*canca;

	i = 0;
	j = 0;
	if (!s2)
		return (0);
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	canca = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!canca)
		return (NULL);
	while (s1[i])
		canca[j++] = s1[i++];
	i = 0;
	while (s2[i])
		canca[j++] = s2[i++];
	canca[j] = '\0';
	free (s1);
	return (canca);
}

char	*ft_strdup(const char *s1)
{
	char	*re;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	re = (char *)malloc((i + 1) * sizeof(char));
	if (!re)
		return (NULL);
	i = -1;
	while (s1[++i])
		re[i] = s1[i];
	re[i] = '\0';
	return (re);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putchar(tab[i]);
		i++;
	}
}
