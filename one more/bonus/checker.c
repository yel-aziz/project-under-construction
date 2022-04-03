/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:02:54 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/02 15:00:01 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"


void	ft_todo_helper(t_stack *va, char *p)
{
	 if(ft_strncmp(p,"rr\n") == 0)
	rr(va);
	else if(ft_strncmp(p,"rrr\n") == 0)
	rrr(va);
	else if(ft_strncmp(p,"rra\n") == 0)
	rra(va);
	else if(ft_strncmp(p,"rrb\n") == 0)
	rrb(va);
	else if(ft_strncmp(p,"sa\n") == 0)
	sa_swap(va);
	else
	{
		putstr("EROOR\n");
		exit(0);
	}
}

void	ft_todo(char *p, t_stack *va)
{	
	
	if(ft_strncmp(p,"rb\n") == 0)
	rb(va);
	else if(ft_strncmp(p,"ra\n") == 0)
	ra(va);
	else if(ft_strncmp(p,"pa\n") == 0)
	{
		pa(va->a,va->b[va->index_stack_temp], va);
		va->index_stack_temp -= 1;
	}
	else if(ft_strncmp(p,"pb\n") == 0)
	{
		pb(va->b,va->a[va->index_stack], va);
		va->index_stack -= 1;
	}
	else if(ft_strncmp(p,"sb\n") == 0)
	sb_swap(va);
	else
		ft_todo_helper(va, p);
}

int	is_sorted(t_stack *va)
{
	int	i;
	int	j;

	i = 0;

	while (i < va->index_stack)
	{
		j = i +1;
		while (j <= va->index_stack)
		{
			if(va->a[i] > va->a[j])
			{
				j++;
			}
			else
			return(1);
		}
		i++;
	}
	return(0);
}

void	ft_checker(t_stack *va)
{
	int i;
	int	j;

	i = 0;
	j = 0;

	while (i < va->index_stack)
	{
		j = i + 1;
		while (j <= va->index_stack)
		{
			if(va->a[i] == va->a[j])
			{
				putstr("Error\n");
				free(va->a);
				free(va->b);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void free_all(t_stack *v, int *tmp) {
	if (v->a)
		free(v->a);
	if (v->b)
		free(v->b);
	if (tmp)
		free(tmp);
}

int main(int ac, char **av)
{
	char *c;
	ac = 0;
	t_stack va;
	ft_parcing(&va, av);
	ft_checker(&va);
	c = get_next_line(0);
	while (c != NULL)
	{
		ft_todo(c, &va);
		free(c);
		c = get_next_line(0);
	}
	
	if(is_sorted(&va) == 1)
	{
		putstr("KO\n");
	}
	else
		putstr("OK\n");
	//free_all(&va, tmp);
	return 0;
}