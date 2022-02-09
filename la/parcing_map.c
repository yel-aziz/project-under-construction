/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:48:49 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/02/09 17:10:14 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**parcing_map(int fd, char *tr)
{
	char	str;
	int		b;
	int		h;
	char	**k;

	b = 1;
	h = 0;
	while (b != 0)
	{
		b = read(fd, &str, 1);
		if (b != 0)
			tr[h++] = str;
		tr[h] = '\0';
	}
	close(fd);
	k = ft_split(tr, '\n');
	return (k);
}
