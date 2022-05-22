/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:50:27 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/05/22 19:10:01 by yel-aziz         ###   ########.fr       */
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

char	**ft_split(char const *s, char c);
int     ft_strcmp( char *s1,  char *s2);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int     ft_strchr(char *s, char c);
size_t	ft_strlen(char *p);
void	ft_putstr_fd(char *s, int fd);
void	get_line(int fd, int fd_direction);
void	ft_putchar_fd(char c, int fd);

#endif
