/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:03:17 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/04 00:06:07 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct va
{
	int	*a;
	int	*b;
	int	index_stack;
	int	index_stack_temp;
}t_stack;

char			*ft_strjoin(char	*s1, char	*s2);
char			*ft_strdup(const char *s1);
char			**ft_split(char const *s, char c);
void			ft_putchar(char c);
void			ft_putstr(char *tab);
void			pa(int *a, int b, t_stack *va);
void			pb(int *b, int a, t_stack *va);
void			ra(t_stack *va);
void			rb(t_stack *va);
void			rra(t_stack *va);
void			rrb(t_stack *va);
long long		ft_atoi(const char *str);
int				ft_strlen(const char *p);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_action(t_stack *va, char *gnt, int *tmp);
void			rr(t_stack *va);
void			rrr(t_stack *va);
int				is_sorted(t_stack *va);
void			last_check(t_stack *va, int	*tmp);
void			print_table(int *tab, int len);
void			rev_tab(t_stack *va, int i);
void			sb(t_stack *va);
void			sa(t_stack *va);
void			ft_checker(t_stack *va, int	*tmp);
void			ft_free_split(char **spl);
void			ss(t_stack *va);
void			malloc_join(char *s1, char *s2);

#endif
