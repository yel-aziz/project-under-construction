/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:35:42 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/01 23:32:21 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	i;
	int	j;
	int	k;
	int	cnt;
	int	index_stack;
	int	index_stack_temp;
	int	index_stack_final;
	int	*a;
	int	*b;
	int	*final;
	int	moyen_stack;
}t_stack;

void			indexing(t_stack *va);
void			sort_index(t_stack *va);
void			push(int *a, int b, t_stack *va);
void			push_b(int *b, int a, t_stack *va);
void			ra(t_stack *va);
void			rb(t_stack *va);
void			rra(t_stack *va);
void			rrb(t_stack *va);
long long int	ft_atoi(const char *str, t_stack *va, char **tmp);
void			putstr(char *c);
void			sa(t_stack *va);
void			ft_sort(t_stack *va);
void			ft_checker(t_stack *va, char **tmp);
int				checkme(t_stack *va);
void			ft_small(t_stack *va);
void			med_sort(t_stack *va);
void			print_table(const int	*a, int k);
void			smaller(t_stack	*va);
void			ft_int(t_stack	*va, long long n, char **tmp);
void			ft_free(t_stack	*va);
void			ft_exit(t_stack *va, char **tmp);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char *s1, char const *s2);
int				ft_strlen(const char *p);
char			*ft_strdup(const char *s1);
void			ft_putchar(char c);
char			**free_split(char **tab);
int				index_stack(int len_argument);
void			ft_free(t_stack *va);
void			ft_main(t_stack *va, int k, int l, char **tmp);
void			ft_maloc(t_stack *va, int i, char **tmp);
int				ft_arrlen(char **tmp);
int				lenword(char const *s, char c);
int				countword(char const *s, char c);
#endif
