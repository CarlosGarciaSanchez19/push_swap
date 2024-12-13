/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosg2 <carlosg2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:53:44 by carlosg2          #+#    #+#             */
/*   Updated: 2024/11/28 12:20:14 by carlosg2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

void	free_and_clear(char **str_s_a, t_list **s_a, t_list **s_b)
{
	free_array(str_s_a, ft_lstsize(*s_a));
	ft_lstclear(s_a, free);
	ft_lstclear(s_b, free);
}

static int
	revinstr_checker(char *str, t_list **stack_a, t_list **stack_b)
{
	t_list	*last_node1;
	t_list	*last_node2;

	if (!ft_strcmp(str, "rra"))
	{
		last_node1 = ft_lstlast(*stack_a);
		return (rrotate(stack_a, &last_node1), 1);
	}
	if (!ft_strcmp(str, "rrb"))
	{
		last_node1 = ft_lstlast(*stack_b);
		return (rrotate(stack_b, &last_node1), 1);
	}
	if (!ft_strcmp(str, "rrr"))
	{
		last_node1 = ft_lstlast(*stack_a);
		last_node2 = ft_lstlast(*stack_b);
		return (rrotate(stack_a, &last_node1),
			rrotate(stack_b, &last_node2), 1);
	}
	else
		return (write(1, "Error\n", 6), 0);
}

int	instr_checker(char *str, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strcmp(str, "sa"))
		return (swap(stack_a), 1);
	if (!ft_strcmp(str, "sb"))
		return (swap(stack_b), 1);
	if (!ft_strcmp(str, "ss"))
		return (swap(stack_a), swap(stack_b), 1);
	if (!ft_strcmp(str, "pa"))
		return (push(stack_b, stack_a), 1);
	if (!ft_strcmp(str, "pb"))
		return (push(stack_a, stack_b), 1);
	if (!ft_strcmp(str, "ra"))
		return (rotate(stack_a), 1);
	if (!ft_strcmp(str, "rb"))
		return (rotate(stack_b), 1);
	if (!ft_strcmp(str, "rr"))
		return (rotate(stack_a), rotate(stack_b), 1);
	if (ft_strlen(str) >= 3)
		return (revinstr_checker(str, stack_a, stack_b));
	else
		return (write(1, "Error\n", 6), 0);
}
