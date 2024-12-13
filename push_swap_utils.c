/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosg2 <carlosg2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:00:39 by carlosg2          #+#    #+#             */
/*   Updated: 2024/11/28 12:13:17 by carlosg2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_stack_a(char **str_stack_a)
{
	t_list	*stack_a;
	t_list	*new_node;
	int		*content;

	stack_a = NULL;
	while (*str_stack_a)
	{
		content = malloc(sizeof(int));
		if (!content)
			return (ft_lstclear(&stack_a, free), NULL);
		*content = ft_atol(*str_stack_a);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			free(content);
			return (ft_lstclear(&stack_a, free), NULL);
		}
		ft_lstadd_back(&stack_a, new_node);
		str_stack_a++;
	}
	return (stack_a);
}

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*fst_node_copy;
	t_list	*snd_node;

	if (!(*stack_a))
		return ;
	fst_node_copy = ft_lstcopynode(*stack_a);
	if (!fst_node_copy)
		return (ft_lstclear(stack_a, free), ft_lstclear(stack_b, free));
	ft_lstadd_front(stack_b, fst_node_copy);
	snd_node = (*stack_a)->next;
	ft_lstdelone(*stack_a, free);
	*stack_a = snd_node;
}

void	swap(t_list **stack)
{
	t_list	*snd_node;

	if (!(*stack) || !(*stack)->next)
		return ;
	snd_node = (*stack)->next;
	(*stack)->next = snd_node->next;
	(snd_node)->next = *stack;
	*stack = snd_node;
}

void	rotate(t_list **stack)
{
	t_list	*fst_node_copy;
	t_list	*snd_node;

	if (!(*stack) || !(*stack)->next)
		return ;
	fst_node_copy = ft_lstcopynode(*stack);
	if (!fst_node_copy)
		return (ft_lstclear(stack, free));
	ft_lstadd_back(stack, fst_node_copy);
	snd_node = (*stack)->next;
	ft_lstdelone(*stack, free);
	*stack = snd_node;
}

void	rrotate(t_list **stack, t_list **last_node)
{
	t_list	*last_node_copy;
	int		size;

	if (!(*stack) || !(*stack)->next || !(*last_node))
		return ;
	size = ft_lstsize(*stack);
	last_node_copy = ft_lstcopynode(*last_node);
	if (!last_node_copy)
		return (ft_lstclear(stack, free));
	ft_lstadd_front(stack, last_node_copy);
	ft_lstdelone(*last_node, free);
	*last_node = ft_lstithnode(*stack, size - 1);
	(*last_node)->next = NULL;
}
