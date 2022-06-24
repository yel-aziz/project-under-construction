/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:20:43 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/24 21:46:39 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	execute_command(char *command)
{
	char	*parsed_command;
	char	**splited_command;

	if (command && (!has_valid_quotes(command)))
	{
		printf("\033[1;31m unclosed quotes not required by the subject\n\033[0m");
		exit_status = 127;
		return ;
	}
	if (command && !*command)
		return ;
	if (!command)
		exit(0);
	parsed_command = parse_quotes(command);
	if (!ft_strcmp("exit", parsed_command))
		exit(0);
	else if (!ft_strcmp("pwd", parsed_command))
		ft_pwd();
	else if (!ft_strcmp("history", parsed_command)
		&& !ft_strcmp("-c", &parsed_command[ft_strlen("history")]))
		rl_clear_history();
	splited_command = split_parse_quotes(command);
	if (!ft_strcmp("echo", splited_command[0]))
		ft_echo(splited_command);
	else
		execute_binary(splited_command);
	free(command);
	clear(splited_command);
}

void	close_all(int *fd, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		close(fd[i]);
		i++;
	}
}

void	execute_sub_command(char **command)
{
	int	i;
	int	j;
	int	*fd;
	int	pid;
	size_t	len;

	i = 0;
	j = 0;
	len = count_commands(command) * 2;
	fd = malloc(len * sizeof(int) * 2);
	create_pipes(fd, len * 2);
	while(command[i])
	{
		if(!has_output_redirection(command[i]))
		{
			pid = fork();
			if (pid == 0)
			{
				if (command[i + 1])
					dup2(fd[j + 1], STDOUT_FILENO);
				if (j)
					dup2(fd[j - 2], STDIN_FILENO);
				close_all(fd, len * 2);
				execute_command(command[i]);
				exit(0);
			}
		}
		i++;
		j += 2;
	}
	close_all(fd, len * 2);
	wait_all(len * 2);
}

void	prompt(int i)
{
	char	*command;
	char	**parsed_command;

	command = readline("\033[0;36m myShell$> \033[0m");
	if (!command)
		exit(0);
	add_history(command);
	if (has_pipe(command) && has_valid_pipes(command))
	{
		parsed_command = split_pipe(command);
		execute_sub_command(parsed_command);
	}
	else if (!has_valid_pipes(command))
		printf("\033[1;31m invalid pipes\n\033[0m");
	else if(has_input_redirection(command) || has_output_redirection(command))
	{
		ft_main_yassir(command);
		// ft_redirection_main(command);
	}
	else
		execute_command(command);
}
