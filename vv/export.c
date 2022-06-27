/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:42:38 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/27 23:03:28 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	len_before_char(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

void	sort_strings(char **strings)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (strings[i])
	{
		j = i + 1;
		while (strings[j])
		{
			if (ft_strcmp(strings[i], strings[j]) <= 0)
			{
				tmp = ft_strdup(strings[i]);
				free(strings[i]);
				strings[i] = ft_strdup(strings[j]);
				free(strings[j]);
				strings[j] = ft_strdup(tmp);
				free(tmp);
			}
			j++;
		}
		i++;
	}
}

void	print_sorted(void)
{
	char	**tmp;
	char	*tt;
	t_list	*current;
	int		i;

	tmp = ft_calloc(sizeof(char *), ft_lstsize(*env) + 1);
	current = *env;
	i = 0;
	while (current)
	{
		tmp[i] = ft_strjoin(current->part_one, "=");
		tt = ft_strdup(tmp[i]);
		free(tmp[i]);
		tmp[i] = ft_strjoin(tt, current->part_two);
		i++;
		current = current->next;
	}
	sort_strings(tmp);
	i = 0;
	while (tmp[i])
	{
		printf("%s\n", tmp[i]);
		i++;
	}
	clear(tmp);
}

void	export(char	**command)
{
	int		i;
	t_list	*var;

	i = 1;
	if (!command[1])
		print_sorted();
	else
	{
		while (command[i])
		{
			var = search_env(env, command[i]);
			if (len_before_char(command[i], '=') != ft_strlen(command[i]))
			{
				if (var)
					copy_env(var, command[i]);
				else
				{
					var = ft_lstnew2(NULL, NULL);
					var->part_one = ft_calloc(len_before_char(command[i], '=')
							+ 1, sizeof(char));
					var->part_two = ft_calloc(ft_strlen(command[i])
							- len_before_char(command[i], '=')
							+ 1, sizeof(char));
					ft_strlcpy(var->part_one, command[i],
						len_before_char(command[i], '=') + 1);
					ft_strlcpy(var->part_two, &command[i]
					[len_before_char(command[i], '=') + 1],
						ft_strlen(command[i])
						- len_before_char(command[i], '='));
					ft_lstadd_back(env, var);
				}
			}
			i++;
		}
	}
}
