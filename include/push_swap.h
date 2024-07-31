/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzubizar <jzubizar@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:09:30 by jzubizar          #+#    #+#             */
/*   Updated: 2023/09/05 18:07:05 by jzubizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define  PUSH_SWAP_H

# include"../libft/libft.h"
# include<unistd.h>
# include<limits.h>

typedef struct s_rotate
{
	int		r;
	int		flag;
	int		len;
}			t_rotate;

typedef struct s_list_pl
{
	void				*content;
	int					price;
	struct s_list_pl	*next;
}						t_list_pl;

void		ft_sa_sb(t_list_pl **lst, char c, int disp);
void		ft_ss(t_list_pl **lst_a, t_list_pl **lst_b, int disp);
void		ft_pa_pb(t_list_pl **lst_from, t_list_pl **lst_to, char c, int disp);
void		ft_ra_rb(t_list_pl **lst, char c, int disp);
void		ft_rr(t_list_pl **lst_a, t_list_pl **lst_b, int disp);
void		ft_rra_rrb(t_list_pl **lst, char c, int disp);
void		ft_rrr(t_list_pl **lst_a, t_list_pl **lst_b, int disp);
int 		ft_rot_quant(int n, t_list_pl *lst);
int	 	   ft_rot_quant2(int n, t_list_pl *lst);
void		ft_order(t_list_pl **lst, int i, char c);
void		ft_ps_sort(t_list_pl **lst_a, t_list_pl **lst_b);
t_list_pl	*ft_create_list(int argc, char **argv, int split);
void		ft_calc_price(t_list_pl **lst, t_list_pl *lst_to, char c);
int			ft_min_price(t_list_pl *lst);
int			ft_rot_eq(t_list_pl *lst, int n);

t_list_pl	*ft_lstnew_plus(void *content);
void		ft_lstadd_back_pl(t_list_pl **lst, t_list_pl *new);
void		ft_lstiter_pl(t_list_pl *lst, void (*f)(void *));
int			ft_lstsize_pl(t_list_pl	*lst);
void		ft_lstadd_front_pl(t_list_pl **lst, t_list_pl *new);

void		ft_free_split(char **split);
int			ft_split_len(char **split);

int			ft_check_sorted(t_list_pl	*lst);
int			ft_check_sortednotordered(t_list_pl	*lst);
void		ft_sort_3(t_list_pl **lst);
void		ft_lstfree(t_list_pl *lst);

#endif