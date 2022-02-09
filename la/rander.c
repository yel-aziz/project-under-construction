/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rander.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:01:04 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/02/09 14:57:39 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_e(t_variable *variable)
{
	if (variable->p[variable->j][variable->i] == 'E')
		mlx_put_image_to_window(variable->mlx, variable->mlx_win,
			variable->exit, variable->x, variable->y);
	if (variable->p[variable->j][variable->i] == 'C')
		mlx_put_image_to_window(variable->mlx, variable->mlx_win,
			variable->collect, variable->x, variable->y);
	if (variable->p[variable->j][variable->i] == 'P')
		mlx_put_image_to_window(variable->mlx, variable->mlx_win,
			variable->player, variable->x, variable->y);
}

void	ft_rander(t_variable *variable)
{
	variable->j = 0;
	variable->x = 0;
	variable->y = 0;
	while (variable->j < variable->w)
	{
		variable->i = 0;
		while (variable->i < variable->l)
		{
			if (variable->p[variable->j][variable->i] == '1')
				mlx_put_image_to_window(variable->mlx, variable->mlx_win,
					variable->wall, variable->x, variable->y);
			if (variable->p[variable->j][variable->i] == '0')
				mlx_put_image_to_window(variable->mlx, variable->mlx_win,
					variable->floor, variable->x, variable->y);
			ft_render_e(variable);
			variable->x += 100;
			variable->i++;
		}
		variable->x = 0;
		variable->y += 100;
		variable->j++;
	}
}
