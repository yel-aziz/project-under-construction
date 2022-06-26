/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gn_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:48:02 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/06/25 23:24:00 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
// size_t	ft_strlen(char *p)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!p)
// 		return (0);
// 	while (p[i] != '\0')
// 		i++;
// 	return (i);
// }

// int	ft_strchr(char *s, char c)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == c)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	int		i;
// 	int		j;
// 	char	*canca;

// 	i = -1;
// 	j = 0;
// 	if (!s2)
// 		return (0);
// 	if (!s1)
// 	{
// 		s1 = (char *)malloc(1);
// 		s1[0] = '\0';
// 	}
// 	canca = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!canca)
// 		return (NULL);
// 	while (s1[++i])
// 		canca[j++] = s1[i];
// 	i = 0;
// 	while (s2[i])
// 		canca[j++] = s2[i++];
// 	canca[j] = '\0';
// 	free(s1);
// 	return (canca);
// }

