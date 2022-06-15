/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:42:58 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/06/15 18:08:55 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing.h"

void    ft_rederiction(char *cmd_byreadline)
{
    char    **splited;
    int     fd;
    int     i;

    i = 0;
    splited = ft_split(cmd_byreadline, ' ');
     while (splited[i])
        i++;
    ft_lastone(splited, i);
}

char *   traitment(char  *cmd)
{
    int     i;
    int     j;
    char    *tab;
    char    *tmp;

    i = 0;
    j = 0;
    while (cmd[i++]);
    tab = malloc(sizeof(char) * 9999);
    tmp = malloc(sizeof(char) * 9999);
    i = 0;
    while (cmd[i])
    {
        if (cmd[i] == '>' && cmd[i + 1] != ' ' && cmd[i - 1] != ' ')
        {
            tab[j] = ' ';
            j++;
            tab[j] = '>';
            j++;
            if (cmd[i + 1] == '>')
            {
                tab[j] = '>';
                j++;
                i++;
            }
           tab[j] = ' ';
            j++;
            i++;
        }
        else
        {
            tab[j] = cmd[i];
            i++;
            j++;
        }
    }
    tab[j] = '\0';
    i = 0;
    j = 0;
    while (tab[i])
    {
        if(tab[i] == '>' && tab[i + 1] == ' ' && tab[i + 2] == '>')
        {
            tmp[j] = '>';
            j++;
            i += 2;
        }
         tmp[j++] = tab[i++];

    }
    tmp[j] = '\0';
    return (tmp);
}

char *   traitment_layer_too(char  *cmd)
{
    int     i;
    int     j;
    char    *tab;
    char    *tmp;

    i = 0;
    j = 0;
    while (cmd[i++]);
    tab = malloc(sizeof(char) * (i + 1));
    i = 0;
    while (cmd[i])
    {
        if (cmd[i] == '<' && cmd[i + 1] != ' ')
        {
            tab[j] = ' ';
            j++;
            tab[j] = '<';
            j++;
            if (cmd[i + 1] == '<')
            {
                tab[j] = '<';
                j++;
                i++;
            }
            tab[j] = ' ';
            j++;
            i++;
        }
        tab[j] = cmd[i];
        i++;
        j++;
    }
    tmp = malloc(sizeof(char) * (j + 1));
    tab[j] = 0;
    i = 0;
    j = 0;
    while (tab[i])
    {
        if(tab[i] == '>' && tab[i + 1] == ' ' && tab[i + 2] == '>')
        {
            tmp[j] = '>';
            j++;
            i += 2;
        }
         tmp[j++] = tab[i++];

    }
    tmp[j] = '\0';
    return (tmp);
}