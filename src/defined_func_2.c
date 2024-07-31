/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defined_func_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzubizar <jzubizar@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:20:03 by josu              #+#    #+#             */
/*   Updated: 2023/09/05 18:41:23 by jzubizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

void	ft_rra_rrb(t_list_pl **lst, char c, int disp)
{
	t_list_pl	*temp;
	t_list_pl	*node;

	if (!*lst || !(*lst)->next)
		return ;
	node = *lst;
	while (node->next->next)
		node = node->next;
	temp = node->next;
	node->next = NULL;
	temp->next = *lst;
	*lst = temp;
	if (disp)
		ft_printf("rr%c\n", c);
}

void	ft_rrr(t_list_pl **lst_a, t_list_pl **lst_b, int disp)
{
	ft_rra_rrb(lst_a, 'a', 0);
	ft_rra_rrb(lst_b, 'b', 0);
	if (disp)
		ft_printf("rrr\n");
}
