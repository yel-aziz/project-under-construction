/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:50:57 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/01/20 00:58:13 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
#include "mlx.h"
#include <stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <stdarg.h>
#include <fcntl.h>



#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1

char    **ft_split(char const *s, char c);
size_t  ft_strlen(char *p);
int     ft_strchr(char *s, char c);
char    *ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
void    ft_putchar(char c);
#endif
#endif