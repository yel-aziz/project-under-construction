/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parcing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:51:21 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/06/26 01:26:53 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

int	countword(char  *s, char c)
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

int	lenword(char  *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char 	*skipspace(char  *s, char c)
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

char	**ft_split(char  *s, char c)
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
int	ft_strcmp_delimiteur(char *s1, char  *s2)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s1[i] && (unsigned char)s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return (1);
		i++;
	}
	return (0);
}