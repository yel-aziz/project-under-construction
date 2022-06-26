/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_parame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 19:10:28 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/06/26 01:26:57 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

int    ft_valid_parame(char    *cmd)
{
    int i;
    int result_qouts;
    int qouts;
    int result;

    i = 0;
    qouts = 0;
    while (cmd[i])
    {
        if( cmd[i] == '"')
        {
            qouts++;
        }
        i++;
    }
    result = (qouts % 2);
    if(result == 0)
    return (0);
    
    return (1);
}

int	fromfirst(char  *set, char  *s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]) == 0)
		{
			break ;
		}
		i++;
	}
	return (i);
}

int	fromlast(char  *set, char  *s1)
{
	int	end_s1;

	end_s1 = ft_strlen(s1) - 1;
	while (end_s1 >= 0)
	{
		if (ft_strchr(set, s1[end_s1]) == 0)
			break ;
		end_s1--;
	}
	return (end_s1);
}

char	*ft_strtrim(char  *s1, char  *set)
{
	size_t	i;
	char	*ptr;
	size_t	end_s1;
	size_t	index;

	if (!set)
		return (NULL);
	if (!s1)
		return (NULL);
	i = 0;
	index = 0;
	i = fromfirst(set, s1);
	if (i == ft_strlen(s1))
		return (NULL);
	end_s1 = fromlast(set, s1);
	ptr = (char *)malloc(end_s1 - i + 2);
	if (!ptr)
		return (NULL);
	while (i <= end_s1)
		ptr[index++] = s1[i++];
	ptr[index] = '\0';
	return (ptr);
}
