/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:03:03 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/03 22:04:18 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_int(long long	n, t_stack *va, int *tmp)
{
	if (n > 2147483647 || n < -2147483648)
	{
		ft_putstr("Eroor\n");
		free(tmp);
		free(va->a);
		free(va->b);
		exit(0);
	}
}

void indexing_b(t_stack *va, int i)
{
	va->index_stack = i;
	va->index_stack_temp = -1;	
}

void	main_helper_b(t_stack *va, char **splited, int *tmp)
{
	int			i;
	long long 	n;
	int			k;
	char		*action;

	i = 0;
	n = 0;
	k = 0;
	while (splited[i])
	{
		n = ft_atoi(splited[i]);
		ft_int(n, va, tmp);
		tmp[i] = (int)n;
		i++;
	}
	 i -= 1;
	while (i >= 0)
	{
		va->a[k++] = tmp[i--];
	}
	ft_free_split(splited);
	indexing_b(va, k - 1);
	ft_checker(va, tmp);
	if(va->index_stack == -1)
		exit(0);
	action = get_next_line(0);
	while (action != NULL)
	{
		ft_action(va, action, tmp);
		free(action);
		action = get_next_line(0);
	}
	last_check(va, tmp);
}

int	main(int ac, char **av)
{
	t_stack	va;
	int		i;
	char	*tmp;
	int		*rev;
	char	**splited;

	ac = 0;
	i = 1;
	tmp = ft_strdup(" ");
	while (av[i])
	{
		tmp = ft_strjoin(tmp, av[i++]);
		tmp = ft_strjoin(tmp, " ");
	}
	splited = ft_split(tmp, ' ');
	free(tmp);
	i = 0;
	while (splited[i])
	i++;
	va.a = malloc(sizeof(int) * i);
	va.b = malloc(sizeof(int) * i);
	rev = malloc(sizeof(int) * i);
	if(!va.a || !va.b ||!rev)
		exit(0);
	main_helper_b(&va, splited, rev);
}