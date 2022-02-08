/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:06:59 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/02/08 20:12:02 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **parcing_map(int fd)
{
	char *a = NULL;
	char **p = NULL;
  
	
    char line[9999] = {0};
    int ret = 1;
    char c;
    int i = 0;

	
    while((ret = read(fd, &c, 1) > 0) && c != '\0')
    {
        line[i++] = c;
    }
    a = ft_strjoin(a,line);
	p = ft_split(a,'\n');
    return(p);
}

int key_hook(int keycode, t_variable *variable)
{
     ft_finder(variable);
  
    ft_keyhok_up_left(variable, keycode);
    keyhoks_down_right(variable, keycode);
    if (keycode == 53)
    {
        mlx_destroy_window(variable->mlx,variable->mlx_win);
        exit(0);
    }
    
    mlx_clear_window(variable->mlx,variable->mlx_win);
    ft_rander(variable);
	return (0);
}

int ft_exit()
{
    exit(0);
    
}

int calcule_l(char **p)
{
    int i;
    i = 0;
    while (p[0][i])
    {
        i++;
    }
    return(i);
}

int calcule_w(char **p)
{
    int i;
    i = 0;
    while (p[i])
    {
        i++;
    }
    return(i);
}

int main(int ac,char **c)
{
    if (ac !=  2)
    {
        return(0);
    }
    
    t_variable variable;
    t_map so_te;
  
	int fd = open(c[1], O_RDONLY);

	        variable.p = parcing_map(fd);
            variable.l = calcule_l(variable.p);
            variable.w = calcule_w(variable.p);
            variable.mlx = mlx_init();
            variable.mlx_win = mlx_new_window(variable.mlx, (variable.l * 100), (variable.w * 100), "so_long");
            variable.n = testeur_map(variable.p,&so_te);
            if (variable.n == 0)
            {
                exit(0);
            }
            ft_converter(&variable);
            ft_rander(&variable);
             mlx_key_hook(variable.mlx_win, key_hook, &variable);
            mlx_hook(variable.mlx_win, 17, (1L<<17),ft_exit, &variable);
             variable.k = so_te.c;
    mlx_loop(variable.mlx);
}

	