/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_again.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:11:33 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/04 00:36:03 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	countword(char const *s, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (*s && *s == c)
		s++;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c) || s[i + 1] == '\0')
			count++;
		i++;
	}
	return (count);
}

int	lenword(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char const	*skipspace(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return (s);
}

char	**ft_free(char **ar)
{
	free (ar);
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
			return (ft_free(ar));
		k = 0;
		while (k < len)
			ar[f][k++] = *s++;
		ar[f++][k] = '\0';
	}
	ar[f] = NULL;
	return (ar);
}
