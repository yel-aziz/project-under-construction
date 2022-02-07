/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:06:59 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/02/07 22:34:19 by yel-aziz         ###   ########.fr       */
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
    if(keycode == 13)
    {
        if (variable->p[variable->i-1][variable->j] == '0')
        {
            variable->p[variable->i-1][variable->j] = 'P';
            variable->p[variable->i][variable->j] = '0';
            variable->i -= 1;
        }
        else if(variable->p[variable->i-1][variable->j] == 'C')
        {
            variable->p[variable->i-1][variable->j] = 'P';
            variable->p[variable->i][variable->j] = '0';
            variable->i -= 1;
             variable->k--;
        }
         else if(variable->p[variable->i-1][variable->j] == 'E' && variable->k == 0)
        {
            mlx_destroy_window(variable->mlx,variable->mlx_win);
            exit(0);
        }
    }
    if (keycode == 2)
    {
        if (variable->p[variable->i][variable->j+1] == '0')
        {
            variable->p[variable->i][variable->j + 1] = 'P';
            variable->p[variable->i][variable->j] = '0';
            variable->i += 1;
        }
        else if (variable->p[variable->i][variable->j+1] == 'C')
        {
            variable->p[variable->i][variable->j + 1] = 'P';
            variable->p[variable->i][variable->j] = '0';
            variable->i += 1;
             variable->k--;
        }
        else if (variable->p[variable->i][variable->j+1] == 'E' && variable-> k == 0)
        {
           mlx_destroy_window(variable->mlx,variable->mlx_win);
           exit(0);
        }
    }
    if (keycode == 0)
    {
        if (variable->p[variable->i][variable->j-1] == '0')
        {
            variable->p[variable->i][variable->j - 1] = 'P';
            variable->p[variable->i][variable->j] = '0';
            variable->i -= 1;
        }
       else if(variable->p[variable->i][variable->j-1] == 'C')
        {
            variable->p[variable->i][variable->j - 1] = 'P';
            variable->p[variable->i][variable->j] = '0';
            variable->i -= 1;
            variable->k--;
        }
        else if(variable->p[variable->i][variable->j-1] == 'E' && variable-> k == 0)
        {
            mlx_destroy_window(variable->mlx,variable->mlx_win);
            exit(0);
        }
        
    }
     if (keycode == 1)
    {
        if (variable->p[variable->i+1][variable->j] == '0' )
        {
            variable->p[variable->i+1][variable->j] = 'P';
            variable->p[variable->i][variable->j] = '0';
            variable->i -= 1;
        }
         else if(variable->p[variable->i+1][variable->j] == 'C')
        {
            variable->p[variable->i+1][variable->j] = 'P';
            variable->p[variable->i][variable->j] = '0';
            variable->i -= 1;
            variable->k--;
        }
        else if(variable->p[variable->i+1][variable->j] == 'E' && variable-> k == 0)
         {
            mlx_destroy_window(variable->mlx,variable->mlx_win);
            exit(0);
        }
    }
    mlx_clear_window(variable->mlx,variable->mlx_win);
    ft_rander(variable);
	return (0);
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

int main()
{
    t_variable variable;
    t_map so_te;
  
	int fd = open("map.ber", O_RDONLY);

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
             variable.k = so_te.c;

    mlx_loop(variable.mlx);
}

	