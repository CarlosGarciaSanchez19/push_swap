/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosg2 <carlosg2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:45:15 by carlosg2          #+#    #+#             */
/*   Updated: 2024/11/28 12:13:17 by carlosg2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_arrsize(char **array)
{
	int	i;

	i = 0;
	while (*array)
	{
		array++;
		i++;
	}
	return (i);
}

int	str_is_digit(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	parse_input(char **input)
{
	int	i;
	int	j;

	if (!input)
		return (0);
	i = 0;
	while (input[i])
	{
		if (!str_is_digit(input[i]))
			return (write(1, "Error\n", 6), 0);
		if ((input[i][0] != '0' && !ft_atol(input[i]))
			|| ft_atol(input[i]) > INT_MAX || ft_atol(input[i]) < INT_MIN)
			return (write(1, "Error\n", 6), 0);
		j = i - 1;
		while (j >= 0)
		{
			if (ft_atol(input[j]) == ft_atol(input[i]))
				return (write(1, "Error\n", 6), 0);
			j--;
		}
		i++;
	}
	if (i && !input[i])
		return (1);
	return (write(1, "Error\n", 6), 0);
}

char	**join_and_split(char **input)
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
