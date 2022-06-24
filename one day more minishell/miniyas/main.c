/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:20:20 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/24 21:45:13 by yel-aziz         ###   ########.fr       */
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

int	main(void)
{
	char *test;

	signal(SIGINT, handle);
	signal(SIGQUIT, SIG_IGN);
	while(1)
	{
		prompt(0);
	}
}
