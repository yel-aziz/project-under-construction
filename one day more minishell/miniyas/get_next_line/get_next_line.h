/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:19:49 by ysakine           #+#    #+#             */
/*   Updated: 2022/05/16 12:36:25 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../minishell.h"

void	ft_bzero(void *s, size_t l);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(char *s1);
// char	*ft_strjoin(char *s1, char *s2);
// size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*get_next_line(int fd);
// size_t	ft_strlen(char *s);
void	*ft_calloc(size_t count, size_t size);

#endif
