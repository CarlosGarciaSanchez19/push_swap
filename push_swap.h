/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosg2 <carlosg2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:06:25 by carlosg2          #+#    #+#             */
/*   Updated: 2024/11/28 12:13:17 by carlosg2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct moves_stack
{
	int	*num;
	int	*pos;
}	t_mvs_s;

long	ft_atol(const char *str);
int		ft_isdigit(int c);
int		ft_arrsize(char **array);
int		str_is_digit(char *str);
char	**join_and_split(char **input);
int		parse_input(char **input);
char	*ft_strdup(const char *src);
char	**ft_split(char const *str, char c);
void	free_array(char **array, int arr_elements);
char	*ft_strjoin(char const *s1, char const *s2);
void	*free_var(void **var);
int		ft_abs(int n);
int		ft_max(int a, int b);
int		ft_lstmin(t_list *lst);
void	free_and_clear(char **str_s_a, t_list **s_a, t_list **s_b);
int		instr_checker(char *str, t_list **stack_a, t_list **stack_b);
void	push_swap(t_list **stack_a, t_list **stack_b);
int		check_sorted_desc(t_list *stack);
void	instruction(char *str, t_list **stack_a, t_list **stack_b);
void	sorting_first_phase(t_list **stack_a, t_list **stack_b);
void	sorting_second_phase(t_list **stack_a, t_list **stack_b);
void	*move_instruct_first_phase(t_list **stack_a, t_list **stack_b);
int		min_moves_pos(int sz_a, int sz_b, int *num_mvs_s_a, t_mvs_s *mvs_s_b);
void	apply_instr(t_list **s_a, t_list **s_b, t_mvs_s *mvs_a, t_mvs_s *mvs_b);
int		*moves_within_stack(t_list *stack);
void	move_instruct_second_phase(t_list **stack_a, t_list **stack_b);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_printf(char const *s, ...);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putunsnbr_fd(unsigned int n, int fd);
int		ft_putnbr_hex_fd(uintptr_t n, int fd, unsigned int capital);
int		ft_putpointer_fd(uintptr_t p, int fd);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstithnode(t_list *lst, int i);
void	ft_lstsprint(t_list *lst1, t_list *lst2);
t_list	*ft_lstcopynode(t_list *node);
t_list	*create_stack_a(char **str_stack_a);
void	push(t_list **stack_a, t_list **stack_b);
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	rrotate(t_list **stack, t_list **last_node);

#endif
