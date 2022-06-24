/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:20:36 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/25 00:21:56 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <editline/readline.h>
# include <signal.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
// # include "../parcing/parcing.h"
// # include "get_next_line/get_next_line.h"
int		exit_status;
char	**ft_split(char  *s, char c);
// void    ft_exec_fd(char **splited);
void	clear(char **arr);
void    ft_main_yassir(char *cmd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strcmp(char *s1, char *s2);
// size_t	ft_stnrcmp(char *s1, char *s2, size_t n);
char	*ft_strjoin(char  *s1, char  *s2);
void	prompt(int i);
char	*ft_strtrim(char *s1, char *set);
void	*ft_calloc(size_t count, size_t size);
void    ft_echo(char **str);
void    ft_pwd(void);
void    ft_env(void);
void	output_redirections(int output_fd, int input_fd);
void	ft_putstr_fd(char *str, int fd);
int	    has_valid_quotes(char *command);
char	*parse_quotes(char *command);
int	    search_binary(char **bin_path, char **command);
void	execute_binary(char **command);
int	    has_pipe(char *command);
char	**split_pipe(char *command);
char	**split_right_arrow(char *command);
char	**split_left_arrow(char *command);
char	**split_right_arrow(char *command);
size_t	count_commands(char **command);
int		has_valid_pipes(char *command);
void	create_pipes(int *fd, size_t len);
void	wait_all(size_t len);
int		has_output_redirection(char *command);
int		has_input_redirection(char *command);
void	execute_command(char *command);
void	append_redirections(char *command);
char	**split_parse_quotes(char *command);
int		is_quote(char c);
char    *ft_strdup(char *str);
// char    *ft_strchr(const char *s, int c);
#endif