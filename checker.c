/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosg2 <carlosg2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:46:38 by carlosg2          #+#    #+#             */
/*   Updated: 2024/11/20 20:34:46 by carlosg2         ###   ########.fr       */
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
		return (free_array(str_stack_a, argc - 1), 1);
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
