/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:15:16 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/01 23:27:39 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char const	*skipspace(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return (s);
}

char	**free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ar;
	int		len;
	int		count;
	int		f;
	int		k;

	count = countword(s, c);
	f = 0;
	ar = (char **)malloc(sizeof(char *) * (count + 1));
	if (!ar || !s)
		return (NULL);
	while (f < count)
	{
		s = skipspace(s, c);
		len = lenword(s, c);
		ar[f] = (char *)malloc(sizeof(char) * (len + 1));
		if (!ar[f])
			return (free_split(ar));
		k = 0;
		while (k < len)
			ar[f][k++] = *s++;
		ar[f++][k] = '\0';
	}
	ar[f] = NULL;
	return (ar);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*canca;

	i = 0;
	j = 0;
	if (!s1 ||!s2)
		return (0);
	canca = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!canca)
		return (NULL);
	while (s1[i])
	{
		canca[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		canca[j] = s2[i];
		i++;
		j++;
	}
	canca[j] = '\0';
	free(s1);
	return (canca);
}
