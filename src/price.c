/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzubizar <jzubizar@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:27:52 by josu              #+#    #+#             */
/*   Updated: 2023/09/05 17:15:13 by jzubizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

int	ft_rot_eq(t_list_pl *lst, int n)
{
	int	rot;
	int	len;

	rot = 0;
	len = ft_lstsize_pl(lst);
	while (lst->next)
	{
		if (n == *(int *)lst->content)
			break ;
		rot++;
		lst = lst->next;
	}
	if (rot > len / 2)
		return ((len - rot) * (-1));
	return (rot);
}

//Final condition for ft_price
//Checks the minimum amount of rots (including rr and rrr)
int	ft_price_condition(int rot_a, int rot_b)
{
	if (rot_a >= 0 && rot_b >= 0)
	{
		if (rot_a > rot_b)
			return (rot_a);
		return (rot_b);
	}
	else if (rot_a < 0 && rot_b < 0)
	{
		if (rot_a < rot_b)
			return (rot_a);
		return (rot_b);
	}
	else if (rot_a >= 0)
		return (rot_a - rot_b);
	return (rot_b - rot_a);
}

//Function that returns the amount of rotations needed for a number to
//correctly pass it to the other stack
int	ft_price(t_list_pl *lst_a, t_list_pl *lst_b, int n, char c)
{
	int	rot_b;
	int	rot_a;

	if (c == 'a')
	{
		rot_a = ft_rot_eq(lst_a, n);
		rot_b = ft_rot_quant(n, lst_b);
	}
	else
	{
		rot_b = ft_rot_eq(lst_b, n);
		rot_a = ft_rot_quant2(n, lst_a);
	}
	return (ft_price_condition(rot_a, rot_b));
}

//Calculates the price of all the components in lst
void	ft_calc_price(t_list_pl **lst, t_list_pl *lst_to, char c)
{
	t_list_pl	*lst_aux;

	lst_aux = *lst;
	while (lst_aux)
	{
		if (c == 'a')
			lst_aux->price = ft_price(*lst, lst_to,
					*(int *)lst_aux->content, c);
		if (c == 'b')
			lst_aux->price = ft_price(lst_to, *lst,
					*(int *)lst_aux->content, c);
		lst_aux = lst_aux->next;
	}
}

//Searches for the minimum price component on the list
int	ft_min_price(t_list_pl *lst)
{
	int	pr;
	int	num;

	if (lst)
	{
		pr = lst->price;
		if (pr < 0)
			pr *= (-1);
		num = *(int *)lst->content;
	}
	while (lst)
	{
		if (lst->price < pr && lst->price >= 0)
		{
			num = *(int *)lst->content;
			pr = lst->price;
		}
		if (lst->price * (-1) < pr && lst->price < 0)
		{
			num = *(int *)lst->content;
			pr = lst->price * (-1);
		}
		lst = lst->next;
	}
	return (num);
}
