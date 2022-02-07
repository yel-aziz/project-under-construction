/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeur_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:05:47 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/02/07 22:30:33 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int p_check(char **p, int n, int m)
{
    int i = 0;
    int j = 0;
    int t = 0;
       while (p[i] && i < n)
        {
            j = 0;
            while(j < m)
            {
                if (p[i][j] == 'P' || p[i][j] == 'C'|| p[i][j] == 'E')
                {
                    t += 1;  
                }
                j++;
            }
            i++;
        } 
        if (t < 3)
        {
            return(0);
        }
        else{
        return(1);}
        
}

void c_check(char **p, int n, int m,t_map *cl)
{
    int i = 0;
    int j = 0;
    int t = 0;
    cl->c =0;
       while (p[i] && i < n)
        {
            j = 0;
            while(j < m)
            {
                if (p[i][j] == 'C')
                {
                    cl->c++;  
                }
                j++;
            }
            i++;
        }     
}

int allcaracter_check(char **p, int n, int m,char c)
{
    int i = 0;
    int j = 0;
    int t = 0;
       while (p[i] && i < n)
        {
            j = 0;
            while(j < m)
            {
                if (p[i][j] == c)
                {
                    return(1);
                }
                j++;
            }
            i++;
        }     
        return (0);
}

int testeur_map(char **p,t_map *test)
{
    test->i = 0;
    test->j = 0;
    test->j = 0;
    test->k = 0;
    test->l = 0;
    test->m = 0;
    test->n = 0;
    test->q = 0;
    test->q = 0;
    test->t = 0;
    test->t = 0;
    int y= 0;

            while (p[test->n])
            {
                test->n++;
            }
            
        while (p[0][test->i] == '1')
        {
            test->i++;
        }
        
        while (p[test->n-1][test->j] == '1')
        {
           test->j++;
        }
            
        if (test->i != test->j )
        {
            return(0);
        }
        
        test->n = 0;
        while (p[test->n] && p[test->n][0] == '1')
        {
            test->n++;
        }
        while (p[test->k] && p[test->k][test->j-1] == '1')
        {
            test->k++;
        }
        
        if (test->n != test->k )
        {
            return(0);
        }
        
        while (test->l != test->k)
        {
            
            while (p[test->l][test->m])
            {
                test->m++;
            }
            test->l++;
        }
        if (test->m != test->i && test->m != test->j)
        {
            return(0);
        }

        while (p[test->q] && test->q < test->n)
        {
           test->w = 0;
            while(test->w < test->m)
            {
                if (p[test->q][test->w] != '0' && p[test->q][test->w] != '1' && p[test->q][test->w] != 'P' && p[test->q][test->w]!= 'C' && p[test->q][test->w] != 'E')
                {
                    return(0);
                }
                test->w++;
            }
            test->q++;
        }
        test->t = p_check(p,test->n, test->m);
        c_check(p,test->n,test->m,test);
         y += allcaracter_check(p, test->n, test->m,'C');
         y += allcaracter_check(p, test->n, test->m,'P');
         y += allcaracter_check(p, test->n, test->m,'E');
         if (y < 3)
         {
             return (0);
         }
         
         printf("\n==> y  = %d\n",y);
        return(1);
}