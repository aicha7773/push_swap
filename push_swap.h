/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:03:05 by aatki             #+#    #+#             */
/*   Updated: 2023/01/13 14:47:38 by aatki            ###   ########.fr       */
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
}					t_pile;

void				putstr(char *s, int j);
void				ft_error(char *s);
int					check_input(char **f);
int					ft_atoi(char *str);
t_pile				*in_pile(char **v, int num);
int					*in_pilee(char **v, int num);
int					*treter(int *tab);
void				affichetab(int *tab);
void				affiche(t_pile *p);
t_pile				*ft_lstnew(int content);
void				ft_lstadd_back(t_pile **lst, t_pile *new);
void				swap(t_pile *l);
void				push(t_pile **aa, t_pile **bb);
void				ft_lstdelfront(t_pile **lst);
void				ft_lstadd_front(t_pile **lst, t_pile *new);
void				ft_lstdelfront(t_pile **lst);
void				ft_lstclear(t_pile **lst, void (*del)(int));
void				push_a_b(t_pile **aa, t_pile **bb);
void				rot(t_pile **a);
void				rot_a_b(t_pile **a, t_pile **b);
void				ft_lstdelback(t_pile **lst);
void				rev_rot(t_pile **a);
t_pile				*ft_lstlast(t_pile *lst);
void				rrev_rot(t_pile **a, t_pile **b);
void				swap_a_b(t_pile *a, t_pile *b);
void				trier(t_pile *l);
int					*struct_to_tab(t_pile *l);
int					ft_lstsize(t_pile *lst);
void				if_trois(t_pile *l);
int					scan_top(t_pile *l, int j);
int					scan_buttom(t_pile *l, int j);
void				ft_top(t_pile **l, t_pile **chank, int i);
void				ft_buttom(t_pile **l, t_pile **chank, int i);
void				main_function(t_pile **l);
#endif
