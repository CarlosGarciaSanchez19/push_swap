/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosg2 <carlosg2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:46:38 by carlosg2          #+#    #+#             */
/*   Updated: 2024/11/23 21:07:13 by carlosg2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static char	*str_without_nl(char *str)
{
	int		i;
	char	*str_cpy;

	if (!str)
		return (NULL);
	i = 0;
	str_cpy = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i] && str[i] != '\n')
	{
		str_cpy[i] = str[i];
		i++;
	}
	str_cpy[i] = '\0';
	return (str_cpy);
}

int	apply_gnl_instr(t_list **stack_a, t_list **stack_b)
{
	char	*str;
	char	*str_cpy;

	str = get_next_line(0);
	str_cpy = str_without_nl(str);
	while (str && str_cpy)
	{
		if (!instr_checker(str_cpy, stack_a, stack_b))
			return (free_var((void **)&str), free_var((void **)&str_cpy), 0);
		free_var((void **)&str);
		free_var((void **)&str_cpy);
		str = get_next_line(0);
		str_cpy = str_without_nl(str);
	}
	return (free_var((void **)&str), free_var((void **)&str_cpy), 1);
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
		return (free_array(str_stack_a, argc - 1), 0);
	stack_a = create_stack_a(str_stack_a);
	if (!stack_a)
		return (free_array(str_stack_a, ft_lstsize(stack_a)), 1);
	stack_b = NULL;
	if (!apply_gnl_instr(&stack_a, &stack_b))
		return (free_and_clear(str_stack_a, &stack_a, &stack_b), 1);
	if (!ft_lstsize(stack_b) && check_sorted_desc(stack_a))
		return (ft_putstr_fd("OK\n", 1),
			free_and_clear(str_stack_a, &stack_a, &stack_b), 0);
	else
		return (ft_putstr_fd("KO\n", 1),
			free_and_clear(str_stack_a, &stack_a, &stack_b), 0);
}
