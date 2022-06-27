/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:20:43 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/27 18:20:22 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_splited_command(char **splited_command)
{
	if (!ft_strcmp("echo", splited_command[0]))
		ft_echo(splited_command);
	else if (!ft_strcmp("cd", splited_command[0]))
		ft_cd(splited_command);
	else if (!ft_strcmp("export", splited_command[0]))
		export(splited_command);
	else if (!ft_strcmp("unset", splited_command[0]))
		unset(splited_command);
	else if (!ft_strcmp("history", splited_command[0])
		&& !ft_strcmp("-c", splited_command[1]))
		rl_clear_history();
	else
		execute_binary(splited_command);
}

void	execute_command(char *command)
{
	char	*parsed_command;
	char	**splited_command;

	if (command && (!has_valid_quotes(command)))
	{
		printf("\033[1;31m unclosed quotes not required by the subject\n\033[0m");
		(*env)->exit_status = 127;
		return ;
	}
	if (command && !*command)
		return ;
	parsed_command = parse_quotes(command);
	if (!ft_strcmp("exit", parsed_command))
		exit(0);
	else if (!ft_strcmp("env", parsed_command))
		ft_env();
	else if (!ft_strcmp("pwd", parsed_command))
		ft_pwd();
	splited_command = split_parse_quotes(command);
	execute_splited_command(splited_command);
	if (command != parsed_command)
		free(parsed_command);
	clear(splited_command);
}

void	close_all(int *fd, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		close(fd[i]);
		i++;
	}
}

void	execute_sub_command(char **command)
{
	int		i;
	int		j;
	int		*fd;
	size_t	len;

	i = 0;
	j = 0;
	len = count_commands(command) * 2;
	fd = malloc(len * sizeof(int) * 2);
	create_pipes(fd, len * 2);
	while (command[i])
	{
		if (has_output_redirection(command[i]))
			ft_main_yassir(command[i]);
		else if (!has_output_redirection(command[i]))
		{
			if (fork() == 0)
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
		else
			execute_command(command[i]);
		i++;
		j += 2;
	}
	close_all(fd, len * 2);
	wait_all(len * 2);
}

void	prompt(void)
{
	char	*command;
	char	**parsed_command;

	command = readline("\033[0;36m myShell$> \033[0m");
	if (!command)
	{
		ft_lstclear(env, free);
		exit(0);
	}
	add_history(command);
	if (has_pipe(command) && has_valid_pipes(command))
	{
		parsed_command = split_pipe(command);
		execute_sub_command(parsed_command);
		clear(parsed_command);
	}
	else if (!has_valid_pipes(command))
		printf("\033[1;31m invalid pipes\n\033[0m");
	else if (has_output_redirection(command) || has_input_redirection(command))
	{
		ft_main_yassir(command);
	}
	else
		execute_command(command);
	free(command);
}
