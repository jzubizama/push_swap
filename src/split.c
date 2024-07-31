/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josu <josu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:13:36 by josu              #+#    #+#             */
/*   Updated: 2023/09/05 16:19:52 by josu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free (split);
}

int	ft_split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	ft_check_sorted(t_list_pl	*lst)
{
	int	*aux1;
	int	*aux2;

	if (!lst)
		return (1);
	while (lst->next)
	{
		aux1 = lst->content;
		aux2 = lst->next->content;
		if (*aux2 < *aux1)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ft_check_sortednotordered(t_list_pl	*lst)
{
	int	*aux1;
	int	*aux2;
	int	flag;
	int	fst;

	flag = 0;
	fst = *(int *)lst->content;
	if (!lst)
		return (1);
	while (lst->next)
	{
		aux1 = lst->content;
		aux2 = lst->next->content;
		if ((*aux2 < *aux1) && flag)
			return (0);
		else if (*aux2 < *aux1)
			flag = 1;
		lst = lst->next;
	}
	if (fst < *(int *)lst->content && flag)
		return (0);
	return (1);
}

void	ft_sort_3(t_list_pl **lst)
{
	if (!ft_check_sortednotordered(*lst))
		ft_sa_sb(lst, 'a', 1);
}
