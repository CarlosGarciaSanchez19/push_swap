/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosg2 <carlosg2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:46:38 by carlosg2          #+#    #+#             */
/*   Updated: 2024/11/28 13:38:34 by carlosg2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

/* static char	*str_without_nl(char *str)
{
	int		i;
	char	*str_cpy;

	if (!str)
		return (NULL);
	i = 0;
	str_cpy = malloc(ft_strlen(str) + 1);
	while (str[i] && str[i] != '\n')
	{
		str_cpy[i] = str[i];
		i++;
	}
	str_cpy[i] = '\0';
	return (str_cpy);
} */

int	apply_and_check(char **str_instr, t_list **stack_a, t_list **stack_b)
{
	char	**arr_instr;
	int		i;

	i = 0;
	arr_instr = ft_split(*str_instr, '\n');
	free_var((void **)str_instr);
	i = 0;
	while (arr_instr[i])
	{
		if (!instr_checker(arr_instr[i], stack_a, stack_b))
			return (free_array(arr_instr, ft_arrsize(arr_instr)), 0);
		i++;
	}
	return (free_array(arr_instr, ft_arrsize(arr_instr)), 1);
}

int	process_gnl_instr(t_list **stack_a, t_list **stack_b)
{
	char	*str_tmp;
	char	*str;
	char	*str_instr;

	str_instr = NULL;
	str = get_next_line(0);
	if (!str)
		return (1);
	str_instr = ft_strdup(str);
	while (str)
	{
		free_var((void **)&str);
		str = get_next_line(0);
		str_tmp = ft_strjoin(str_instr, str);
		free_var((void **)&str_instr);
		str_instr = ft_strdup(str_tmp);
		free_var((void **)&str_tmp);
	}
	return (apply_and_check(&str_instr, stack_a, stack_b));
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**str_stack_a;
	int		i;

	if (argc < 2)
		return (0);
	str_stack_a = join_and_split(argv);
	i = 0;
	if (!parse_input(str_stack_a))
		return (free_array(str_stack_a, ft_arrsize(str_stack_a)), 0);
	stack_a = create_stack_a(str_stack_a);
	if (!stack_a)
		return (free_array(str_stack_a, ft_arrsize(str_stack_a)), 1);
	stack_b = NULL;
	if (!process_gnl_instr(&stack_a, &stack_b))
		return (free_and_clear(str_stack_a, &stack_a, &stack_b), 0);
	if (!ft_lstsize(stack_b) && check_sorted_desc(stack_a))
		return (ft_putstr_fd("OK\n", 1),
			free_and_clear(str_stack_a, &stack_a, &stack_b), 0);
	else
		return (ft_putstr_fd("KO\n", 1),
			free_and_clear(str_stack_a, &stack_a, &stack_b), 0);
}
