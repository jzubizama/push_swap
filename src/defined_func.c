/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defined_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzubizar <jzubizar@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:44:20 by josu              #+#    #+#             */
/*   Updated: 2023/09/05 18:39:57 by jzubizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sa_sb(t_list_pl **lst, char c, int disp)
{
	t_list_pl	*tmp;

	if (!*lst)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	tmp->next = (*lst);
	*lst = tmp;
	if (disp)
		ft_printf("s%c\n", c);
}

void	ft_ss(t_list_pl **lst_a, t_list_pl **lst_b, int disp)
{
	ft_sa_sb(lst_a, 'a', 0);
	ft_sa_sb(lst_b, 'b', 0);
	if (disp)
		ft_printf("ss\n");
}

void	ft_pa_pb(t_list_pl **lst_from, t_list_pl **lst_to, char c, int disp)
{
	t_list_pl	*node;

	if (!*lst_from)
		return ;
	node = *lst_from;
	*lst_from = node->next;
	ft_lstadd_front_pl(lst_to, node);
	if (disp)
		ft_printf("p%c\n", c);
}

void	ft_ra_rb(t_list_pl **lst, char c, int disp)
{
	t_list_pl	*temp;

	if (!*lst || !(*lst)->next)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	temp->next = NULL;
	ft_lstadd_back_pl(lst, temp);
	if (disp)
		ft_printf("r%c\n", c);
}

void	ft_rr(t_list_pl **lst_a, t_list_pl **lst_b, int disp)
{
	ft_ra_rb(lst_a, 'a', 0);
	ft_ra_rb(lst_b, 'b', 0);
	if (disp)
		ft_printf("rr\n");
}
