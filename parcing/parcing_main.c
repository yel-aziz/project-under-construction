/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:50:13 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/05/22 22:33:58 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"


void	get_line(int fd, int fd_direction)
{
	char	*line;

	while (line != NULL)
	{
		line = get_next_line(0);
		ft_putstr_fd(line, fd_direction);
	}
	exit(0);
}

char	*parse_file_name(char *parsed_table, char	*file_name)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (parsed_table[i])
	{
		i++;
	}
	file_name = malloc(sizeof(char ) * i + 1);
	i = 2;
	while (parsed_table[i])
	{
		file_name[j++] = parsed_table[i++];
	}
	file_name[j] = '\0';

	return (file_name);
}

int	main()
{
	char	*cmd;
	int		fd;
	char	*file_name;

	cmd = readline("\033[0;36m myShell$> \033[0m");

	if(ft_strcmp(">",&cmd[0]) == 0 && (ft_strcmp(">",&cmd[1]) == 1))
	{
		file_name = parse_file_name(cmd, file_name);
		if(fork() == 0)
		{
			fd = open(file_name, O_RDWR|O_CREAT| O_TRUNC, 0666);
			get_line(0, fd);	
		}
		wait(NULL);
		main();
	}
	else if (ft_strcmp(">",&cmd[0]) == 0 && (ft_strcmp(">",&cmd[1]) == 0))
	{
		file_name = parse_file_name(cmd, file_name);
		if(fork() == 0)
		{
			fd = open(file_name,  O_RDWR|O_CREAT|O_APPEND, 0666);
			get_line(0, fd);	
		}
		wait(NULL);
		main();
	}
}