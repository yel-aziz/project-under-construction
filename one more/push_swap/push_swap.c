/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:03:27 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/01 23:36:04 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_main(va, k, l, tmp);
	free_split(tmp);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack			va;
	int				i;
	int				j;
	char			*jo;

	ac = 0;
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