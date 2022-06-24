/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakine <ysakine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:19:34 by ysakine           #+#    #+#             */
/*   Updated: 2022/06/18 23:08:10 by ysakine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void    ft_echo(char **str)
{
    int index;
    extern int exit_status;

    index = 1;
    while(str[index] && !ft_strcmp("-n", str[index]))
        index++;
    if(index > 1 && !str[index])
        return ;
    else if (!str[index])
    {
        printf("\n");
        return ;
    }
    if (index > 1 && str[index])
        printf("%s", str[index]);
    else if(str[index])
        printf("%s\n", str[index]);
    if(index > 1 && !ft_strcmp("$?", str[index]))
        printf("%d\n", exit_status);
    else if (!ft_strcmp("$?", str[index]))
        printf("%d", exit_status);
    exit_status = 0;
}

