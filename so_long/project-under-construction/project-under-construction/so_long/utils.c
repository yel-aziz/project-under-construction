/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:33:08 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/01/20 00:58:06 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void ft_putchar(char c)
{
	write(1,&c,1);
}

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

// int main()
// {
//     char s[] = ".ya.ss.ir.";
//     int r = countword(s,'.');
//     printf("%d",r);
// }
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

size_t	ft_strlen(char *p)
{
	size_t	i;

	i = 0;
	if (!p)
		return (0);
	while (p[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*canca;

	i = -1;
	j = 0;
	if (!s2)
		return (0);
	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	canca = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!canca)
		return (NULL);
	while (s1[++i])
		canca[j++] = s1[i];
	i = 0;
	while (s2[i])
		canca[j++] = s2[i++];
	canca[j] = '\0';
	free(s1);
	return (canca);
}

char	*ft_change_text(char *text)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	j = ft_strlen(text);
	if (text[i] == '\0')
	{
		free(text);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * ((j - i) + 1));
	if (!s)
		return (NULL);
	j = 0;
	while (text[i++] != '\0')
	{
		s[j++] = text[i];
	}
	s[j] = '\0';
	free(text);
	return (s);
}

char	*ft_just_line(char *text)
{
	size_t	i;
	size_t	j;
	char	*b;

	j = 0;
	i = 0;
	if (!*text)
		return (0);
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	if (text[i] == '\n')
		i++;
	b = (char *)malloc(sizeof(char) * (i + 1));
	if (!b)
		return (NULL);
	while (j < i)
	{
		b[j] = text[j];
		j++;
	}
	b[j] = '\0';
	return (b);
}

char	*ft_read(char *text, int fd)
{
	char	*p;
	int		n;

	n = 1;
	p = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!p)
		return (NULL);
	while (!(ft_strchr(text, '\n')) && n != 0)
	{
		n = read(fd, p, BUFFER_SIZE);
		if (n == -1)
		{
			free (p);
			return (NULL);
		}
		p[n] = '\0';
			text = ft_strjoin(text, p);
	}
	free (p);
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = ft_read(text, fd);
	if (!text)
		return (NULL);
	line = ft_just_line(text);
	text = ft_change_text(text);
	return (line);
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