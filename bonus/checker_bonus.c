/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzubizar <jzubizar@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:22:42 by jzubizar          #+#    #+#             */
/*   Updated: 2023/09/05 19:19:41 by jzubizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

int	ft_ejec_instr(char *ins, t_list_pl **lst_a, t_list_pl **lst_b)
{
	if (!ft_strncmp(ins, "sa\n", 3))
		ft_sa_sb(lst_a, 'a', 0);
	else if (!ft_strncmp(ins, "sb\n", 3))
		ft_sa_sb(lst_b, 'b', 0);
	else if (!ft_strncmp(ins, "ss\n", 3))
		ft_ss(lst_a, lst_b, 0);
	else if (!ft_strncmp(ins, "pa\n", 3))
		ft_pa_pb(lst_b, lst_a, 'a', 0);
	else if (!ft_strncmp(ins, "pb\n", 3))
		ft_pa_pb(lst_a, lst_b, 'b', 0);
	else if (!ft_strncmp(ins, "ra\n", 3))
		ft_ra_rb(lst_a, 'a', 0);
	else if (!ft_strncmp(ins, "rb\n", 3))
		ft_ra_rb(lst_b, 'b', 0);
	else if (!ft_strncmp(ins, "rr\n", 3))
		ft_rr(lst_a, lst_b, 0);
	else if (!ft_strncmp(ins, "rra\n", 4))
		ft_rra_rrb(lst_a, 'a', 0);
	else if (!ft_strncmp(ins, "rrb\n", 4))
		ft_rra_rrb(lst_b, 'b', 0);
	else if (!ft_strncmp(ins, "rrr\n", 4))
		ft_rrr(lst_a, lst_b, 0);
	else
		return (-1);
	return (0);
}

/* int	ft_check_sorted(t_list_pl	*lst)
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
} */
int	ft_check_line(char **line, t_list_pl **lst_a, t_list_pl **lst_b, int fd)
{
	*line = get_next_line(fd);
	if (*line)
	{
		if (ft_ejec_instr(*line, lst_a, lst_b) == -1)
		{
			free(*line);
			ft_lstfree(*lst_b);
			return (-1);
		}
	}
	return (0);
}

int	ft_read_exec(t_list_pl *lst_a)
{
	int			fd;
	char		*line;
	t_list_pl	*lst_b;

	fd = 0;
	lst_b = NULL;
	line = NULL;
	ft_check_line(&line, &lst_a, &lst_b, fd);
	while (line)
	{
		free(line);
		ft_check_line(&line, &lst_a, &lst_b, fd);
	}
	free (line);
	if (!lst_b && ft_check_sorted(lst_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstfree(lst_a);
	ft_lstfree(lst_b);
	return (0);
}

int	main(int argc, char **argv)
{
	char		**split;
	t_list_pl	*lst_a;

	split = NULL;
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
	if (ft_read_exec(lst_a) == -1)
	{
		ft_printf("Error\n");
		ft_lstfree(lst_a);
		return (3);
	}
}
