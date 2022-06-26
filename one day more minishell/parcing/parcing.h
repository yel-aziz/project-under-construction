/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:50:27 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/06/25 23:24:11 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCING_H
#define PARCING_H


# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../miniyas/minishell.h"
// char	**ft_split(char  *s, char c);

int	fromlast(char  *set, char  *s1);
// // char	*ft_strdup(char *s1);
// // char	**ft_split(char  *s, char c);
// int     ft_strcmp( char *s1,  char  *s2);
char	*get_next_line(int fd);
// char	*ft_strjoin(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
int     ft_strchr(char *s, char c);
// int	ft_strlen(char *p);
void	ft_putstr_fd(char *s, int fd);
// // void	get_line(int fd, int fd_direction);
void	ft_putchar_fd(char c, int fd);
int    ft_valid_parame(char    *cmd);
void    ft_rederiction(char *cmd_byreadline);
char *   traitment(char  *cmd);
// void    ft_lastone(char **splited, int i);
char *   traitment_layer_too(char  *cmd);
char	*ft_strtrim(char  *s1, char  *set);
// char	*ft_remove_qout(char *cmd);
void    ft_open(char    **str, int   i);
int	ft_strcmp_delimiteur(char *s1, char  *s2);
void    ft_exec_fd(char **splited);
void    ft_heardoc_init(char    **splited);

#endif
