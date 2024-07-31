/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josu <josu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 09:50:42 by josu              #+#    #+#             */
/*   Updated: 2023/09/05 15:21:59 by josu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

int	ft_lstsize_pl(t_list_pl	*lst)
{
	int			i;
	t_list_pl	*node;

	i = 0;
	node = lst;
	while (node != NULL)
	{
		i++;
		node = node->next;
	}
	return (i);
}

void	ft_lstiter_pl(t_list_pl *lst, void (*f)(void *))
{
	t_list_pl	*node;

	if (!f)
		return ;
	node = lst;
	while (node)
	{
		f(node->content);
		node = node->next;
	}
}

void	ft_lstadd_back_pl(t_list_pl **lst, t_list_pl *new)
{
	t_list_pl	*node;

	if (*lst != NULL)
	{
		node = *lst;
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
	else
		*lst = new;
}

t_list_pl	*ft_lstnew_plus(void *content)
{
	t_list_pl	*node;

	node = malloc(sizeof(t_list_pl));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->price = 0;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front_pl(t_list_pl **lst, t_list_pl *new)
{
	new->next = *lst;
	*lst = new;
}
