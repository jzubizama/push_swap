/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzubizar <jzubizar@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:24:40 by jzubizar          #+#    #+#             */
/*   Updated: 2023/09/05 19:23:02 by jzubizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

long	ft_long_atoi(const char *str)
{
	unsigned int	i;
	long			sign;
	long			nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr * sign);
}

int	ft_arg_check(char *arg)
{
	int		i;
	long	num;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if ((arg[i] < '0' || arg[i] > '9'))
			return (-1);
		i++;
	}
	if (i > 9)
	{
		num = ft_long_atoi(arg);
		if (num > (long)INT32_MAX || num < (long)INT32_MIN)
			return (-1);
	}
	return (0);
}

int	ft_isinlst(t_list_pl *lst, int num)
{
	while (lst)
	{
		if (num == *(int *)lst->content)
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_list_pl	*ft_lst_add(t_list_pl *lst, int *nbr)
{
	if (!lst)
		lst = ft_lstnew_plus(nbr);
	else
		ft_lstadd_back_pl(&lst, ft_lstnew_plus(nbr));
	return (lst);
}

t_list_pl	*ft_create_list(int argc, char **argv, int split)
{
	int			i;
	int			*nbr;
	t_list_pl	*lst;

	i = 1;
	lst = NULL;
	if (split)
		i = 0;
	while (i < argc)
	{
		if (ft_arg_check(argv[i]) == -1 || ft_isinlst(lst, ft_atoi(argv[i])))
		{
			ft_lstfree(lst);
			return (NULL);
		}
		nbr = malloc(sizeof(int));
		if (!nbr)
			ft_lstfree(lst);
		if (!nbr)
			return (NULL);
		*nbr = ft_atoi(argv[i]);
		lst = ft_lst_add(lst, nbr);
		i++;
	}
	return (lst);
}
