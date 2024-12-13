# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carlosg2 <carlosg2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 19:41:56 by carlosg2          #+#    #+#              #
#    Updated: 2024/11/28 12:23:42 by carlosg2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BNAME = checker

SRCS = push_swap.c push_swap_utils.c push_swap_utils2.c push_swap_utils3.c push_swap_utils4.c ft_atol.c ft_printf.c \
ft_isdigit.c ft_strdup.c ft_printf_utils.c ft_putstr_fd.c ft_putchar_fd.c ft_putnbr_fd.c ft_strlen.c ft_strcmp.c \
ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_split.c \
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_strjoin.c \
ft_lstmap_bonus.c obt_inst_fst_phase.c apply_inst_fst_phase.c main.c

BSRCS = get_next_line.c get_next_line_utils.c checker_utils.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

%.o: %.c
	cc $(CFLAGS) -c $(SRCS)

$(NAME): $(OBJS)
	ar rcs $(NAME).a $(OBJS)
	cc $(CFLAGS) $(NAME).a -o $(NAME)

all: $(NAME)

$(BOBJS): $(BSRCS)
	cc $(CFLAGS) -c $(BSRCS)

$(BNAME): $(NAME) $(BOBJS) checker.c
	ar rcs libchecker.a $(BOBJS)
	cc $(CFLAGS) checker.c $(NAME).a libchecker.a -o checker

bonus: $(BNAME)

clean:
	rm -f $(OBJS) $(BOBJS) checker.o

fclean: clean
	rm -f $(NAME).a libchecker.a
	rm -f $(NAME) checker

re: fclean all

.PHONY: all clean fclean re bonus