/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:20:10 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/27 23:11:02 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*buff;
	size_t			i;

	i = 0;
	buff = malloc(count * size);
	while (i < count * size)
	{
		buff[i] = 0;
		i++;
	}
	return ((void *)buff);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*r;

	i = 0;
	r = (char *)s;
	while (r[i])
	{
		if (c == (int)(r[i]))
			return (&r[i]);
		i++;
	}
	if (c == '\0')
		return (&r[i]);
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*buff;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = 0;
	j = ft_strlen(s1) - 1;
	k = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j && ft_strchr(set, s1[j]))
		j--;
	if (j <= i || !s1[0])
	{
		buff = ft_calloc(1, sizeof(char));
		return (buff);
	}
	buff = ft_calloc(j - i + 2, sizeof(char));
	if (!buff)
		return (0);
	l = j - i + 1;
	while (k < l)
		buff[k++] = s1[i++];
	return (buff);
}
