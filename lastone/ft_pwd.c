/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:19:54 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/20 04:25:31 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void    ft_pwd(void)
{
    char    cwd[1024];

    getcwd(cwd, 1024);
    // printf("%s\n", cwd);
}