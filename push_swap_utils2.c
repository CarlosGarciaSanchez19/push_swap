/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosg2 <carlosg2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:42:47 by carlosg2          #+#    #+#             */
/*   Updated: 2024/11/28 12:03:27 by carlosg2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstcopynode(t_list *node)
{
	t_list	*new_node;
	int		*content;

	content = malloc(sizeof(int));
	if (!content)
		return (NULL);
	*content = *(int *)(node->content);
	new_node = ft_lstnew(content);
	if (!new_node)
	{
		free(content);
		return (NULL);
	}
	return (new_node);
}

t_list	*ft_lstithnode(t_list *lst, int i)
{
	int		j;
	t_list	*iterlst;

	if (i < 0)
		return (NULL);
	j = 0;
	iterlst = lst;
	while (iterlst && j < i)
	{
		iterlst = iterlst->next;
		j++;
	}
	return (iterlst);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	*free_var(void **var)
{
	if (*var)
	{
		free(*var);
		*var = NULL;
	}
	return (NULL);
}

int	ft_lstmin(t_list *lst)
{
	t_list	*iterlst;
	t_list	*min_node;
	int		i;
	int		min;

	iterlst = lst;
	i = 0;
	min = 0;
	while (iterlst)
	{
		min_node = ft_lstithnode(lst, min);
		if (*(int *)(min_node->content) > *(int *)(iterlst->content))
			min = i;
		iterlst = iterlst->next;
		i++;
	}
	return (min);
}
