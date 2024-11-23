/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosg2 <carlosg2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:25:22 by carlosg2          #+#    #+#             */
/*   Updated: 2024/11/17 18:16:34 by carlosg2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	revinstructions(char *str, t_list **stack_a, t_list **stack_b)
{
	t_list	*last_node1;
	t_list	*last_node2;

	if (!ft_strcmp(str, "rra"))
	{
		ft_printf("%s\n", str);
		last_node1 = ft_lstlast(*stack_a);
		return (rrotate(stack_a, &last_node1));
	}
	if (!ft_strcmp(str, "rrb"))
	{
		ft_printf("%s\n", str);
		last_node1 = ft_lstlast(*stack_b);
		return (rrotate(stack_b, &last_node1));
	}
	if (!ft_strcmp(str, "rrr"))
	{
		ft_printf("%s\n", str);
		last_node1 = ft_lstlast(*stack_a);
		last_node2 = ft_lstlast(*stack_b);
		return (rrotate(stack_a, &last_node1), rrotate(stack_b, &last_node2));
	}
}

void	instruction(char *str, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strcmp(str, "sa"))
		return (ft_printf("%s\n", str), swap(stack_a));
	if (!ft_strcmp(str, "sb"))
		return (ft_printf("%s\n", str), swap(stack_b));
	if (!ft_strcmp(str, "ss"))
		return (ft_printf("%s\n", str), swap(stack_a), swap(stack_b));
	if (!ft_strcmp(str, "pa"))
		return (ft_printf("%s\n", str), push(stack_b, stack_a));
	if (!ft_strcmp(str, "pb"))
		return (ft_printf("%s\n", str), push(stack_a, stack_b));
	if (!ft_strcmp(str, "ra"))
		return (ft_printf("%s\n", str), rotate(stack_a));
	if (!ft_strcmp(str, "rb"))
		return (ft_printf("%s\n", str), rotate(stack_b));
	if (!ft_strcmp(str, "rr"))
		return (ft_printf("%s\n", str), rotate(stack_a), rotate(stack_b));
	if (ft_strlen(str) == 3)
		return (revinstructions(str, stack_a, stack_b));
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	*moves_within_stack(t_list *stack)
{
	int	*moves_stack;
	int	sz;
	int	i;

	sz = ft_lstsize(stack);
	moves_stack = malloc(sz * sizeof(int));
	i = 0;
	while (i < sz)
	{
		if (i <= sz / 2)
			moves_stack[i] = i;
		else
			moves_stack[i] = sz - i;
		i++;
	}
	return (moves_stack);
}

int	min_moves_pos(int sz_a, int sz_b, int *num_mvs_s_a, t_mvs_s *mvs_s_b)
{
	int	mv;
	int	i;
	int	pos_min_moves;

	mv = num_mvs_s_a[0] + mvs_s_b->num[0];
	pos_min_moves = 0;
	i = 0;
	while (++i < sz_a)
	{
		if (mv > num_mvs_s_a[i] + mvs_s_b->num[i])
		{
			mv = num_mvs_s_a[i] + mvs_s_b->num[i];
			pos_min_moves = i;
		}
		if ((i <= sz_a / 2 && mvs_s_b->pos[i] <= sz_b / 2)
			|| (i > sz_a / 2 && mvs_s_b->pos[i] > sz_b / 2))
		{
			if (mv > ft_max(num_mvs_s_a[i], mvs_s_b->num[i]))
			{
				mv = ft_max(num_mvs_s_a[i], mvs_s_b->num[i]);
				pos_min_moves = i;
			}
		}
	}
	return (pos_min_moves);
}
