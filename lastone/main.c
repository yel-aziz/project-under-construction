/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:20:20 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/21 00:50:25 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	handle(int sig)
{
	if (sig == SIGINT)
	{
		write(1,"\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
    	rl_redisplay();
	}
}

void	quit_shell(int a)
{
	exit(0);
}

int	main(int ac, char **av, char **envp)
{
	int		i;

	i = 0;
	env = ft_calloc(sizeof(t_list *), 1);
	while(envp[i])
	{
		ft_lstadd_back(env, ft_lstnew(envp[i]));
		i++;
	}
	signal(SIGINT, handle);
	signal(SIGQUIT, SIG_IGN);
	while(1)
	{
		prompt(0);
	}
}
