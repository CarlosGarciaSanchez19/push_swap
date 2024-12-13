/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosg2 <carlosg2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:18:51 by carlosg2          #+#    #+#             */
/*   Updated: 2024/11/23 20:42:58 by carlosg2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_instr_snd_phase(t_list **s_a, t_list **s_b, int pos_a)
{
	int		i;
	int		greater;
	int		sz_a;

	i = 0;
	sz_a = ft_lstsize(*s_a);
	greater = ((*(int *)(*s_b)->content
				> *(int *)ft_lstithnode(*s_a, pos_a)->content));
	if (pos_a <= sz_a / 2)
	{
		while (i < pos_a + greater)
		{
			instruction("ra", s_a, s_b);
			i++;
		}
	}
	else
	{
		while (i < sz_a - pos_a - greater)
		{
			instruction("rra", s_a, s_b);
			i++;
		}
	}
}

void	move_instruct_second_phase(t_list **stack_a, t_list **stack_b)
{
	t_list	*iter_a;
	int		i;
	int		absdiff;
	int		pos_a;

	iter_a = *stack_a;
	i = 0;
	absdiff = ft_abs(*(int *)(*stack_b)->content - *(int *)(*stack_a)->content);
	pos_a = 0;
	while (iter_a && iter_a->next)
	{
		if (absdiff > ft_abs(*(int *)(*stack_b)->content
			- *(int *)iter_a->next->content))
		{
			absdiff = ft_abs(*(int *)(*stack_b)->content
					- *(int *)iter_a->next->content);
			pos_a = i + 1;
		}
		iter_a = iter_a->next;
		i++;
	}
	apply_instr_snd_phase(stack_a, stack_b, pos_a);
}

void	sorting_second_phase(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_b))
	{
		move_instruct_second_phase(stack_a, stack_b);
		instruction("pa", stack_a, stack_b);
	}
	if (ft_lstmin(*stack_a) <= ft_lstsize(*stack_a) / 2)
		while (!check_sorted_desc(*stack_a))
			instruction("ra", stack_a, stack_b);
	else
		while (!check_sorted_desc(*stack_a))
			instruction("rra", stack_a, stack_b);
}

void	sorting_first_phase(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		move_instruct_first_phase(stack_a, stack_b);
		instruction("pb", stack_a, stack_b);
	}
	if (ft_lstsize(*stack_a) == 3)
	{
		while (!check_sorted_desc(*stack_a))
		{
			if (*(int *)(*stack_a)->content
				> *(int *)(*stack_a)->next->content
				&& *(int *)(*stack_a)->content
				< *(int *)(*stack_a)->next->next->content)
				instruction("sa", stack_a, stack_b);
			else if (*(int *)(*stack_a)->content
				< *(int *)(*stack_a)->next->content
				&& *(int *)(*stack_a)->content
				> *(int *)(*stack_a)->next->next->content)
				instruction("rra", stack_a, stack_b);
			else
				instruction("ra", stack_a, stack_b);
		}
	}
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	if (!check_sorted_desc(*stack_a) && ft_lstsize(*stack_a) > 1)
	{
		if (ft_lstsize(*stack_a) > 3)
		{
			instruction("pb", stack_a, stack_b);
			instruction("pb", stack_a, stack_b);
		}
		sorting_first_phase(stack_a, stack_b);
		sorting_second_phase(stack_a, stack_b);
	}
	return (ft_lstclear(stack_a, free), ft_lstclear(stack_b, free));
}
