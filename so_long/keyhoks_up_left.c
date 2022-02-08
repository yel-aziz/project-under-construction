/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhoks_up_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:59:41 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/02/08 20:00:44 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_keyhok_up_left(t_variable *variable,int keycode)
{
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
}