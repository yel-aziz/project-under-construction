/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 07:55:40 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/26 10:43:15 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

int	extended(char **splited)
{
	int		i;
	char	*name;
	int		fd;

	i = 0;
	fd = -1;
	while (splited[i] && (ft_strcmp(splited[i], ">") && ft_strcmp(splited[i], ">>")))
		i++;
	if (!splited[i])
		return (fd);
	while (splited[i])
		i++;
	ft_open(splited, i);
	name = parse_quotes(splited[i - 1]);
	if (!ft_strcmp(splited[i - 2], ">"))
		fd = open(name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	else if (!ft_strcmp(splited[i - 2], ">>"))
		fd = open(name, O_CREAT | O_RDWR | O_APPEND, 0644);
	return (fd);
}