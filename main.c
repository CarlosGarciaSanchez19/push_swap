/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosg2 <carlosg2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:05:59 by carlosg2          #+#    #+#             */
/*   Updated: 2024/11/20 20:35:09 by carlosg2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_input(char **input)
{
	int	i;
	int	j;

	if (!input)
		return (0);
	i = 0;
	while (input[i])
	{
		if ((input[i][0] != '0' && !ft_atoi(input[i]))
			|| ft_atoi(input[i]) > INT_MAX || ft_atoi(input[i]) < INT_MIN)
			return (write(1, "Error\n", 6), 0);
		j = i - 1;
		while (j >= 0)
		{
			if (ft_atoi(input[j]) == ft_atoi(input[i]))
				return (write(1, "Error\n", 6), 0);
			j--;
		}
		i++;
	}
	if (i && !input[i])
		return (1);
	return (write(1, "Error\n", 6), 0);
}

static char	**join_and_split(char **input)
{
	char	**str_array;
	char	*str;
	char	*tmp;
	int		i;

	str = ft_strdup(input[1]);
	if (!str)
		return (NULL);
	i = 2;
	while (input[i])
	{
		tmp = ft_strjoin(str, " ");
		free_var((void **)&str);
		if (!tmp)
			return (free_var((void **)&str));
		str = ft_strjoin(tmp, input[i]);
		if (!str)
			return (free_var((void **)&tmp));
		free_var((void **)&tmp);
		i++;
	}
	str_array = ft_split(str, ' ');
	if (!str_array)
		return (free_var((void **)&str));
	return (free_var((void **)&str), str_array);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**str_stack_a;

	if (argc < 2)
		return (0);
	str_stack_a = join_and_split(argv);
	if (!parse_input(str_stack_a))
		return (free_array(str_stack_a, argc - 1), 1);
	stack_b = NULL;
	stack_a = create_stack_a(str_stack_a);
	if (!stack_a)
		return (free_array(str_stack_a, ft_lstsize(stack_a)), 1);
	if (ft_lstsize(stack_a) == 2 && !check_sorted_desc(stack_a))
	{
		instruction("sa", &stack_a, &stack_b);
		return (free_array(str_stack_a, ft_lstsize(stack_a)),
			ft_lstclear(&stack_a, free), 0);
	}
	else if (ft_lstsize(stack_a) <= 2)
		return (free_array(str_stack_a, ft_lstsize(stack_a)),
			ft_lstclear(&stack_a, free), 0);
	return (free_array(str_stack_a, ft_lstsize(stack_a)),
		push_swap(&stack_a, &stack_b), 0);
}
