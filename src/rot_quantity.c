/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_quantity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josu <josu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:56:55 by josu              #+#    #+#             */
/*   Updated: 2023/09/05 15:57:30 by josu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

//Final condition for ft_rot_quant
int	ft_desc_cond(t_list_pl *lst_aux, t_rotate r, int n)
{
	if (r.r == r.len - 1 && r.flag)
	{
		if (lst_aux)
		{
			if (n > *(int *)lst_aux->next->content
				|| n < *(int *)lst_aux->content)
			{
				if (r.flag <= r.len / 2)
					return (r.flag);
				return ((r.len - r.flag) * (-1));
			}
		}
		return (0);
	}
	return (r.r);
}

//Function to set the rotations needed to set the number n
//in the list --> DESCENDING order
int	ft_rot_quant(int n, t_list_pl *lst)
{
	t_rotate	r;
	t_list_pl	*lst_aux;

	if (!lst)
		return (0);
	r.r = 0;
	r.flag = 1;
	lst_aux = NULL;
	r.len = ft_lstsize_pl(lst);
	while (lst->next)
	{
		r.r++;
		if (n < *(int *)lst->content && n > *(int *)lst->next->content)
		{
			r.flag = 0;
			break ;
		}
		if (*(int *)lst->content < *(int *)lst->next->content)
		{
			r.flag = r.r;
			lst_aux = lst;
		}
		lst = lst->next;
	}
	return (ft_desc_cond(lst_aux, r, n));
}

//Final condition for ft_rot_quant2
int	ft_asc_cond(t_list_pl *lst_aux, t_rotate r, int n)
{
	if (r.r == r.len - 1 && r.flag)
	{
		if (lst_aux)
		{
			if (n < *(int *)lst_aux->next->content
				|| n > *(int *)lst_aux->content)
			{
				if (r.flag <= r.len / 2)
					return (r.flag);
				return ((r.len - r.flag) * (-1));
			}
		}
		return (0);
	}
	if (r.r <= r.len / 2)
		return (r.r);
	return ((r.len - r.r) * (-1));
}

//Function to set the rotations needed to set the number n
//in the list --> ASCENDING order
int	ft_rot_quant2(int n, t_list_pl *lst)
{
	t_rotate	r;
	t_list_pl	*lst_aux;

	if (!lst)
		return (0);
	r.r = 0;
	r.flag = 1;
	lst_aux = NULL;
	r.len = ft_lstsize_pl(lst);
	while (lst->next)
	{
		r.r++;
		if (n > *(int *)lst->content && n < *(int *)lst->next->content)
		{
			r.flag = 0;
			break ;
		}
		if (*(int *)lst->content > *(int *)lst->next->content)
		{
			r.flag = r.r;
			lst_aux = lst;
		}
		lst = lst->next;
	}
	return (ft_asc_cond(lst_aux, r, n));
}
