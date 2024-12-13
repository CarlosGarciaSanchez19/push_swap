/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosg <carlosg@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:00:37 by carlosg           #+#    #+#             */
/*   Updated: 2024/10/10 02:29:47 by carlosg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		ft_modstrlen(char *str, char c, int flag);
char	*ft_freevar(char **var);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_modstrdup(char *src);
char	*ft_modstrjoin(char **s1, char *s2);

#endif
