/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_inst_fst_phase.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosg2 <carlosg2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:34:30 by carlosg2          #+#    #+#             */
/*   Updated: 2024/11/17 13:53:04 by carlosg2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	repeat_inst_a(t_list **s_a, t_list **s_b, int n_mvs_a, int pos_a)
{
	while (n_mvs_a > 0)
	{
		if (pos_a <= ft_lstsize(*s_a) / 2)
			instruction("ra", s_a, s_b);
		else
			instruction("rra", s_a, s_b);
		n_mvs_a--;
	}
}

static void
	repeat_inst_b(t_list **s_a, t_list **s_b, int n_mvs_b, int pos_b)
{
	while (n_mvs_b > 0)
	{
		if (pos_b <= ft_lstsize(*s_b) / 2)
			instruction("rb", s_a, s_b);
		else
			instruction("rrb", s_a, s_b);
		n_mvs_b--;
	}
}

static void
	repeat_inst_rr(t_list **s_a, t_list **s_b, int *n_mvs_a, int *n_mvs_b)
{
	while (*n_mvs_a > 0 && *n_mvs_b > 0)
	{
		instruction("rr", s_a, s_b);
		(*n_mvs_a)--;
		(*n_mvs_b)--;
	}
}

static void
	repeat_inst_rrr(t_list **s_a, t_list **s_b, int *n_mvs_a, int *n_mvs_b)
{
	while (*n_mvs_a > 0 && *n_mvs_b > 0)
	{
		instruction("rrr", s_a, s_b);
		(*n_mvs_a)--;
		(*n_mvs_b)--;
	}
}

void	apply_instr(t_list **s_a, t_list **s_b, t_mvs_s *mvs_a, t_mvs_s *mvs_b)
{
	int	n_mvs_b;
	int	n_mvs_a;
	int	pos_b;
	int	pos_a;

	pos_a = *(mvs_a->pos);
	n_mvs_b = (int)(mvs_b->num)[pos_a];
	pos_b = (int)(mvs_b->pos)[pos_a];
	n_mvs_a = (int)(mvs_a->num)[pos_a];
	if (pos_a <= ft_lstsize(*s_a) / 2 && pos_b <= ft_lstsize(*s_b) / 2)
		repeat_inst_rr(s_a, s_b, &n_mvs_a, &n_mvs_b);
	else if (pos_a > ft_lstsize(*s_a) / 2 && pos_b > ft_lstsize(*s_b) / 2)
		repeat_inst_rrr(s_a, s_b, &n_mvs_a, &n_mvs_b);
	repeat_inst_a(s_a, s_b, n_mvs_a, pos_a);
	repeat_inst_b(s_a, s_b, n_mvs_b, pos_b);
}
