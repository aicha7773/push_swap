/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:26:08 by aatki             #+#    #+#             */
/*   Updated: 2023/02/09 15:44:40 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_ppile
{
	int				data;
	struct t_ppile	*next;
	int				index;
}					t_pile;

typedef struct t_hankss
{
	int				size;
	int				offset;
	int				start;
	int				end;
	int				middle;
	int				i;
}					t_hanks;

t_pile				*ft_pop(t_pile **stack);
void				putstr(char *s);
void				ft_error(void);
void				check_input(char **f);
int					ft_atoi(char *str);
t_pile				*in_pile(char **v);
void				affiche(t_pile *p);
t_pile				*ft_lstnew(int content);
void				ft_lstadd_back(t_pile **lst, t_pile *new);
void				swap(t_pile *l);
void				push(t_pile **aa, t_pile **bb);
void				ft_lstdelfront(t_pile **lst);
void				ft_lstadd_front(t_pile **lst, t_pile *new);
void				ft_lstdelfront(t_pile **lst);
void				push_a_b(t_pile **aa, t_pile **bb);
void				rot(t_pile **a);
void				rot_a_b(t_pile **a, t_pile **b);
void				ft_lstdelback(t_pile **lst);
void				rev_rot(t_pile **a);
t_pile				*ft_lstlast(t_pile *lst);
void				rrev_rot(t_pile **a, t_pile **b);
void				swap_a_b(t_pile *a, t_pile *b);
int					*struct_to_tab(t_pile *l);
int					ft_lstsize(t_pile *lst);
void				if_three(t_pile *l);
void				ft_top(t_pile **l, t_pile **chank, int i, char c);
void				ft_buttom(t_pile **l, t_pile **chank, int i, char c);
void				indicer(t_pile *l);
void				trier_tab(int *tab, int size);
int					*struct_to_tab(t_pile *l);
int					ft_pos(t_pile *lst, int val);
int					no_need(t_pile *l);
void				duplicated(t_pile *l);
void				which_way(t_pile **l, t_pile **b, int val, char c);
int					min_list(t_pile *l);
void				main_function(t_pile **l);
int					max_list(t_pile *l);
void				if_five(t_pile **l);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_free(t_pile *t);
int					pos(t_pile *l, int d);
void				affichetab(int *tab, int size);
int					ft_lstlastint(t_pile *lst);
void				which_way2(t_pile **l, int pos);
void				please(t_pile **a, t_pile **b);
void				for_norm(t_pile **l, t_pile **b, int *tab, t_hanks *t);
char				**ft_split(char *s, char c);
char				*ft_substr(char *s, unsigned int start, size_t len);
size_t				ft_strlen(char *c);
char				**ft_freee(char **p, int len);
#endif
