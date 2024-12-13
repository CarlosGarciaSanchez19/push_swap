/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosg2 <carlosg2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:05:59 by carlosg2          #+#    #+#             */
/*   Updated: 2024/11/23 21:07:24 by carlosg2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**str_stack_a;
	int		str_arr_sz;

	if (argc < 2)
		return (0);
	str_stack_a = join_and_split(argv);
	str_arr_sz = ft_arrsize(str_stack_a);
	if (parse_input(str_stack_a))
	{
		stack_b = NULL;
		stack_a = create_stack_a(str_stack_a);
		if (!stack_a)
			return (free_array(str_stack_a, str_arr_sz), 1);
		if (str_arr_sz == 2 && !check_sorted_desc(stack_a))
		{
			instruction("sa", &stack_a, &stack_b);
			return (free_array(str_stack_a, str_arr_sz),
				ft_lstclear(&stack_a, free), 0);
		}
		return (free_array(str_stack_a, str_arr_sz),
			push_swap(&stack_a, &stack_b), 0);
	}
	return (free_array(str_stack_a, str_arr_sz), 0);
}
