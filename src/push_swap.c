/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzubizar <jzubizar@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:08:48 by jzubizar          #+#    #+#             */
/*   Updated: 2023/09/05 19:22:25 by jzubizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

/* void	ft_print_lst(t_list_pl *lst)
{
	int	*aux;

	aux = (lst->content);
	ft_printf("%i (%i)\n", *aux, lst->price);
	while (lst->next)
	{
		lst = lst->next;
		aux = (lst->content);
		ft_printf("%i (%i)\n", *aux, lst->price);
	}
}

void	ft_print_lsts(t_list_pl *lst_a, t_list_pl *lst_b)
{
	int	*auxa;
	int	*auxb;

	if (!lst_a)
	{
		ft_printf("b:\n");
		ft_print_lst(lst_b);
		return ;
	}
	if (!lst_b)
	{
		ft_printf("a:\n");
		ft_print_lst(lst_a);
		return ;
	}
	auxa = lst_a->content;
	ft_printf("%i (%i)", *auxa, lst_a->price);
	if (*auxa > 100)
		ft_printf(" ");
	else if (*auxa > 10)
		ft_printf("  ");
	else if (*auxa >= 0)
		ft_printf("   ");
	auxb = lst_b->content;
	ft_printf("%i (%i)\n", *auxb, lst_b->price);
	while (lst_a->next || lst_b->next)
	{
		if (lst_a->next)
		{
			lst_a = lst_a->next;
			auxa = (lst_a->content);
			ft_printf("%i (%i)", *auxa, lst_a->price);
		}
		else
			ft_printf(" ");
		if (*auxa > 100)
			ft_printf(" ");
		else if (*auxa > 10)
			ft_printf("  ");
		else if (*auxa >= 0)
			ft_printf("   ");
		if (lst_b->next)
		{
			lst_b = lst_b->next;
			auxb = (lst_b->content);
			ft_printf("%i (%i)\n", *auxb, lst_b->price);
		}
		else
			ft_printf("\n");
	}
} */

void	ft_rotation_condit(t_list_pl **lst_a,
		t_list_pl **lst_b, int rot_a, int rot_b)
{
	while (rot_a != 0 || rot_b != 0)
	{
		if (rot_a > 0 && rot_b > 0)
			ft_rr(lst_a, lst_b, 1);
		else if (rot_a < 0 && rot_b < 0)
			ft_rrr(lst_a, lst_b, 1);
		if (rot_a > 0 && rot_b <= 0)
			ft_ra_rb(lst_a, 'a', 1);
		else if (rot_a < 0 && rot_b >= 0)
			ft_rra_rrb(lst_a, 'a', 1);
		if (rot_b > 0 && rot_a <= 0)
			ft_ra_rb(lst_b, 'b', 1);
		else if (rot_b < 0 && rot_a >= 0)
			ft_rra_rrb(lst_b, 'b', 1);
		if (rot_a > 0)
			rot_a--;
		else if (rot_a < 0)
			rot_a++;
		if (rot_b > 0)
			rot_b--;
		else if (rot_b < 0)
			rot_b++;
	}
}

/* void	ft_ps_back_to_a(t_list_pl **lst_a, t_list_pl **lst_b)
{
	int	num;
	int	rot_a;
	int	rot_b;

	while (ft_lstsize_pl(*lst_b) > 0)
	{
		ft_calc_price(lst_b, *lst_a, 'b');
		num = ft_min_price(*lst_b);
		rot_b = ft_rot_eq(*lst_b, num);
		rot_a = ft_rot_quant2(num, *lst_a);
		ft_rotation_condit(lst_a, lst_b, rot_a, rot_b);
		ft_pa_pb(lst_b, lst_a, 'a', 1);
	}
	ft_order(lst_a, 1, 'a');
} */
void	ft_ps_back_to_a(t_list_pl **lst_a, t_list_pl **lst_b)
{
	int	rot;
	int	*cont;

	while (ft_lstsize_pl(*lst_b) > 0)
	{
		cont = (*lst_b)->content;
		rot = ft_rot_quant2(*cont, *lst_a);
		while (rot > 0)
		{
			ft_ra_rb(lst_a, 'a', 1);
			rot--;
		}
		while (rot < 0)
		{
			ft_rra_rrb(lst_a, 'a', 1);
			rot++;
		}
		ft_pa_pb(lst_b, lst_a, 'a', 1);
	}
	ft_order(lst_a, 1, 'a');
}

void	ft_a_to_b(t_list_pl **lst_a, t_list_pl **lst_b)
{
	int	num;
	int	rot_a;
	int	rot_b;

	ft_calc_price(lst_a, *lst_b, 'a');
	num = ft_min_price(*lst_a);
	rot_a = ft_rot_eq(*lst_a, num);
	rot_b = ft_rot_quant(num, *lst_b);
	ft_rotation_condit(lst_a, lst_b, rot_a, rot_b);
	ft_pa_pb(lst_a, lst_b, 'b', 1);
}

void	ft_ps_sort(t_list_pl **lst_a, t_list_pl **lst_b)
{
	if (ft_lstsize_pl(*lst_a) > 3)
		ft_pa_pb(lst_a, lst_b, 'b', 1);
	if (ft_lstsize_pl(*lst_a) > 3)
		ft_pa_pb(lst_a, lst_b, 'b', 1);
	while (ft_lstsize_pl(*lst_a) > 3 && !ft_check_sortednotordered(*lst_a))
	{
		ft_a_to_b(lst_a, lst_b);
	}
	ft_sort_3(lst_a);
	ft_ps_back_to_a(lst_a, lst_b);
}

int	main(int argc, char **argv)
{
	char		**split;
	t_list_pl	*lst_a;
	t_list_pl	*lst_b;

	split = NULL;
	lst_b = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		lst_a = ft_create_list(ft_split_len(split), split, 1);
		ft_free_split(split);
	}
	else
		lst_a = ft_create_list(argc, argv, 0);
	if (!lst_a)
	{
		ft_printf("Error\n");
		return (2);
	}
	if (!ft_check_sorted(lst_a))
		ft_ps_sort(&lst_a, &lst_b);
	ft_lstfree(lst_a);
	return (0);
}
