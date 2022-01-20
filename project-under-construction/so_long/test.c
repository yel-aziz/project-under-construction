/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:06:59 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/01/20 01:15:37 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"



void parcing_map(int fd)
{
	char *a = NULL;
	char **p = NULL;
    void	*mlx;
	void	*mlx_win;
	void	*img_obj;
	int k;
	int b;
    char line[9999] = {0};
    int ret = 1;
    char c;
    int i = 0;

	
    while((ret = read(fd, &c, 1) > 0) && c != '\0')
    {
        line[i++] = c;
    }
    
	a = ft_strdup(line);
	p = ft_split(a,'\n');
	mlx = mlx_init();
    
	mlx_win = mlx_new_window(mlx, 920, 720, "so_long");
    
	img_obj = mlx_xpm_file_to_image(mlx,"yassir.xpm", &k, &b);
	mlx_put_image_to_window(mlx,mlx_win,img_obj,200,200);
    
    mlx_loop(mlx);
    printf("%c",p[3][2]);
}


int main()
{
	int fd = open("map.ber", O_RDONLY);
	parcing_map(fd);
	
}








	

// // int	main(void)
// {
	
// 	void	*mlx;
// 	void	*mlx_win;
// 	void	*img_obj;
// 	int a;
// 	int b;
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 920, 720, "Hello world!");
// 	img_obj = mlx_xpm_file_to_image(mlx,"yassir.xpm", &a, &b);
// 	mlx_put_image_to_window(mlx,mlx_win,img_obj,200,200);
	
	
// 	mlx_loop(mlx);
// }