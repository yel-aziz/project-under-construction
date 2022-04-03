/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uneedit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:37:06 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/01 23:40:11 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main_to_folder(t_stack *va, char *jo)
{
	char			**tmp;
	int				k;
	long long int	n;
	int				l;
	int				i;

	i = 0;
	tmp = NULL;
	k = 0;
	l = 0;
	n = 0;
	tmp = ft_split(jo, ' ');
	free(jo);
	ft_maloc(va, ft_arrlen(tmp), tmp);
	i = 0;
	while (tmp[i])
	{
		n = ft_atoi(tmp[i++], va, tmp);
		ft_int(va, n, tmp);
		va->a[k++] = n;
	}
	free_split(tmp);
	return (0);
}

void	ft_parcing(t_stack *va, char **av)
{
	t_stack			va;
	int				i;
	int				j;
	char			*jo;

	i = 1;
	j = 0;
	while (av[i])
		i++;
	i -= 1;
	jo = (char *)malloc(sizeof(char));
	jo[0] = ' ';
	j = 1;
	while (j <= i)
	{
		jo = ft_strjoin(jo, av[j]);
		jo = ft_strjoin(jo, " ");
		j++;
	}
	main_to_folder(&va, jo);
}