/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzubizar <jzubizar@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:55:30 by josu              #+#    #+#             */
/*   Updated: 2023/09/05 18:13:07 by jzubizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

//Function to know the rotations needed to order the list
//in DESCENDING order
int	ft_rot_min(t_list_pl *lst_b)
{
	int	r;
	int	next;
	int	len;
	int	flag;

	r = 0;
	len = ft_lstsize_pl(lst_b);
	flag = 0;
	while (lst_b->next)
	{
		r++;
		next = *(int *)lst_b->next->content;
		if (next > *(int *)lst_b->content)
		{
			flag = 1;
			break ;
		}
		lst_b = lst_b->next;
	}
	if (r == len - 1 + flag)
		return (0);
	else if (r <= len / 2)
		return (r);
	return ((len - r) * (-1));
}

//Function to know the rotations needed to order the list
//in ASCENDING order
int	ft_rot_asc(t_list_pl *lst)
{
	int	r;
	int	next;
	int	len;
	int	flag;

	r = 0;
	len = ft_lstsize_pl(lst);
	flag = 0;
	while (lst->next)
	{
		r++;
		next = *(int *)lst->next->content;
		if (next < *(int *)lst->content)
		{
			flag = 1;
			break ;
		}
		lst = lst->next;
	}
	if (r == len - 1 + flag)
		return (0);
	else if (r <= len / 2)
		return (r);
	return ((len - r) * (-1));
}

//Function to put a sorted but not ordered list in order
void	ft_order(t_list_pl **lst, int i, char c)
{
	int	rot;

	if (i == -1)
		rot = ft_rot_min(*lst);
	else
		rot = ft_rot_asc(*lst);
	while (rot > 0)
	{
		ft_ra_rb(lst, c, 1);
		rot--;
	}
	while (rot < 0)
	{
		ft_rra_rrb(lst, c, 1);
		rot++;
	}
}

void	ft_lstfree(t_list_pl *lst)
{
	t_list_pl	*node;

	ft_lstiter_pl(lst, free);
	node = lst;
	while (lst)
	{
		node = lst;
		lst = node->next;
		free (node);
	}
}
