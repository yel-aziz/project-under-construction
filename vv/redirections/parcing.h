/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:50:27 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/06/27 23:27:16 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCING_H
# define PARCING_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../minishell.h"

int		fromlast(char *set, char *s1);
char	*get_next_line(int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_valid_parame(char *cmd);
void	ft_rederiction(char *cmd_byreadline);
char	*traitment(char *cmd);
char	*traitment_layer_too(char *cmd);
char	*ft_strtrim(char *s1, char *set);
void	ft_open(char **str, int i);
int		ft_strcmp_delimiteur(char *s1, char *s2);
void	ft_exec_fd(char **splited);
void	ft_heardoc_init(char **splited);
int		extended(char **splited);
void	ft_main_yassir(char *cmd);

#endif
