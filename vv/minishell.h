/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:20:36 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/27 23:14:23 by yel-aziz         ###   ########.fr       */
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
# include <errno.h>
# include "get_next_line/get_next_line.h"
# include "redirections/parcing.h"

// typedef struct t_env
// {
// 	int		exit_status;
// 	t_env	*next;
// } t_env;
typedef struct s_list
{
	char			*part_one;
	char			*part_two;
	int				exit_status;
	struct s_list	*next;
}t_list;

t_list	**env;
char	**ft_split(char const *s, char c);
void	clear(char **arr);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strcmp(char *s1, char *s2);
size_t	ft_strncmp(char *s1, char *s2, int n);
char	*ft_strjoin(char const *s1, char const *s2);
void	prompt(void);
char	*ft_strtrim(char *s1, char *set);
void	*ft_calloc(size_t count, size_t size);
void	ft_echo(char **str);
void	ft_pwd(void);
void	ft_env(void);
void	output_redirections(int output_fd, int input_fd);
void	ft_putstr_fd(char *str, int fd);
int		has_valid_quotes(char *command);
char	*parse_quotes(char *command);
int		search_binary(char **bin_path, char **command);
void	execute_binary(char **command);
int		has_pipe(char *command);
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
void	ft_cd(char **cmd);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void*));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstnew2(char *part_one, char *part_two);
void	ft_lstswap(t_list *node0, t_list *node1);
int		ft_lstsize(t_list *lst);
char	*ft_strdup(const char *s1);
void	export(char	**command);
size_t	len_before_char(char *s, char c);
t_list	*search_env(t_list **env, char *part_one);
void	copy_env(t_list *node, char	*env);
void	unset(char	**command);
char	*ft_strchr(const char *s, int c);
void	ft_heredoc_utils(char *del);
void	ft_heredoc_com(char **splited);
char	*ft_find_cmd(char **splited);
#endif