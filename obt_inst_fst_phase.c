/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_inst_fst_phase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosg2 <carlosg2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:49:47 by carlosg2          #+#    #+#             */
/*   Updated: 2024/11/17 16:17:29 by carlosg2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted_desc(t_list *stack)
{
	t_list	*iterlst;

	iterlst = stack;
	while (iterlst->next)
	{
		if (*(int *)(iterlst->content) > *(int *)(iterlst->next)->content)
			return (0);
		iterlst = iterlst->next;
	}
	return (1);
}

void	trvrs_stack(t_list *s_a, t_list *s_b, t_mvs_s *mv_stack, int i)
{
	t_list		*iter_b;
	int			j;
	int			diff;

	diff = ft_abs(*(int *)s_a->content - *(int *)s_b->content);
	(mv_stack->num)[i] = (*(int *)s_a->content - *(int *)s_b->content < 0);
	(mv_stack->pos)[i] = 0;
	iter_b = s_b;
	j = 0;
	while (iter_b && iter_b->next)
	{
		if (diff > ft_abs(*(int *)s_a->content - *(int *)iter_b->next->content))
		{
			diff = *(int *)s_a->content - *(int *)iter_b->next->content;
			if (j + 1 <= ft_lstsize(s_b) / 2)
				(mv_stack->num)[i] = j + 1 + (diff < 0);
			else
				(mv_stack->num)[i] = ft_lstsize(s_b) - j - 1 - (diff < 0);
			diff = ft_abs(*(int *)s_a->content - *(int *)iter_b->next->content);
			(mv_stack->pos)[i] = j + 1;
		}
		iter_b = iter_b->next;
		j++;
	}
}

void	num_and_pos(t_list *stack_a, t_list *stack_b, t_mvs_s *mv_stack)
{
	int		i;

	if (!mv_stack->num || !mv_stack->pos)
		return ;
	i = 0;
	while (stack_a)
	{
		trvrs_stack(stack_a, stack_b, mv_stack, i);
		stack_a = stack_a->next;
		i++;
	}
}

t_mvs_s	*create_moves_stack(t_list *stack_a, t_list *stack_b)
{
	t_mvs_s	*moves_stack;

	moves_stack = malloc(sizeof(t_mvs_s));
	moves_stack->num = (int *)malloc(ft_lstsize(stack_a) * sizeof(int));
	moves_stack->pos = (int *)malloc(ft_lstsize(stack_a) * sizeof(int));
	if (!(moves_stack->pos) || !(moves_stack->num) || !(moves_stack))
		return (free_var((void **)&moves_stack->num),
			free_var((void **)&moves_stack),
			free_var((void **)&moves_stack));
	num_and_pos(stack_a, stack_b, moves_stack);
	return (moves_stack);
}

void	*move_instruct_first_phase(t_list **stack_a, t_list **stack_b)
{
	t_mvs_s			*mvs_s_b;
	t_mvs_s			*mvs_s_a;
	int				sz_a;
	int				sz_b;

	mvs_s_a = malloc(sizeof(t_mvs_s));
	mvs_s_a->pos = malloc(sizeof(int));
	mvs_s_a->num = moves_within_stack(*stack_a);
	mvs_s_b = create_moves_stack(*stack_a, *stack_b);
	if (!mvs_s_b || !mvs_s_a || !mvs_s_a->num
		|| !mvs_s_a->pos)
		return (free_var((void **)&mvs_s_b),
			free_var((void **)&mvs_s_a->num),
			free_var((void **)&mvs_s_a->pos),
			free_var((void **)&mvs_s_a));
	sz_a = ft_lstsize(*stack_a);
	sz_b = ft_lstsize(*stack_b);
	*(mvs_s_a->pos) = min_moves_pos(sz_a, sz_b, mvs_s_a->num, mvs_s_b);
	apply_instr(stack_a, stack_b, mvs_s_a, mvs_s_b);
	return (free_var((void **)&mvs_s_b->num), free_var((void **)&mvs_s_b->pos),
		free_var((void **)&mvs_s_b), free_var((void **)&mvs_s_a->num),
		free_var((void **)&mvs_s_a->pos), free_var((void **)&mvs_s_a));
}
