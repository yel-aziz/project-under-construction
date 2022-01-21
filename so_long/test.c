/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:06:59 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/01/21 16:27:10 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"


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


int main()
{
	int fd = open("map.ber", O_RDONLY);
	void	*mlx;
	void	*mlx_win;
	void	*img_obj;
    int     k;
	int     b;
    int     j = 0;
    int x = 10;
    int i = 0;

    int y = 10;
    char **p;
    
	        p = parcing_map(fd);
            mlx = mlx_init();
            mlx_win = mlx_new_window(mlx, 1980, 1980, "so_long");
            
            // while (j != '\n')
            // {
            //     if(p[0][j] == '1')
            //     {
            //         img_obj = mlx_xpm_file_to_image(mlx,"wall.xpm", &k, &b);
            //         mlx_put_image_to_window(mlx,mlx_win,img_obj,y,9);
            //         y = y+80; 
            //     }
            //     while (/* condition */)
            //     {
            //         /* code */
            //     }
                
               
                
            //     j++;
            // }
            while (j < 8) {
                i = 0;
                y = 10;
                x = 10;
                while (i < 15) {
                    if (p[j][i] == '1') {
                        // printf("hello\n");
                        img_obj = mlx_xpm_file_to_image(mlx,"wall.xpm", &k, &b);
                        mlx_put_image_to_window(mlx,mlx_win,img_obj,y,x);
                        y = y+101;
                        x += 101;
                    }
                    else if (p[j][i] == '0'){
                        // img_obj = mlx_xpm_file_to_image(mlx,"wall.xpm", &k, &b);
                        // mlx_put_image_to_window(mlx,mlx_win,img_obj,10,x);
                        // x += 101;
                    }
                    i++;
                }
                j++;
            }
            mlx_loop(mlx);
            
            
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