/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:20:01 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/24 21:42:46 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear(char **arr)
{
	size_t	i;

	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	if (arr)
		free(arr);
}

int	is_quote(char c)
{
	return (c == '\'' || c =='"' || c == '`');
}

static int	count_words(char const *str, char c)
{
	int		count;
	int		i;
	char	quote;

	count = 0;
	i = 0;
	quote = 0;
	while (str[i])
	{
		if (is_quote(str[i]) && !quote)
			quote = str[i++];
		while (str[i] == c && !quote)
			i++;
		if (quote)
			while (quote && str[i] != quote)
				i++;
		// else
			while (str[i] != c && str[i])
				i++;
		// if (quote)
		// 	i++;
		quote = 0;
		count++;
	}
	return (count);
}

static char	**fill_array_with_words(char **arr, char const *str, char c)
{
	int		index;
	int		i;
	int		tmp_i;
	char	quote;

	index = 0;
	i = 0;
	quote = 0;
	while (str[i])
	{
		if (is_quote(str[i]) && !quote)
			quote = str[i++];
		while (str[i] == c && !quote)
			i++;
		tmp_i = i;
		if (quote)
			while (quote && str[i] && str[i] != quote)
				i++;
		// else
			while (str[i] != c && str[i])
				i++;
		arr[index] = ft_calloc(i - tmp_i + 1, sizeof(char));
		if (!arr[index])
			return (NULL);
		ft_strlcpy(arr[index], str + tmp_i, i - tmp_i + 1);
		index++;
		// if (quote)
		// 	i++;
		quote = 0;
	}
	arr[index] = NULL;
	return (arr);
}

// char	**ft_split(char  *s, char c)
// {
// 	char	**array;
// 	int		words_count;

// 	if (!s)
// 		return (NULL);
// 	words_count = count_words(s, c);
// 	array = ft_calloc((words_count + 1) , sizeof(char *));
// 	if (!array)
// 		return (NULL);
// 	if (!fill_array_with_words(array, s, c))
// 	{
// 		clear(array);
// 		return (NULL);
// 	}
// 	return (array);
// }
