/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosg2 <carlosg2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:58:06 by carlosg           #+#    #+#             */
/*   Updated: 2024/10/10 02:29:22 by carlosg2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

static char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	if ((unsigned char)c == '\0')
		return ((char *)(s + ft_modstrlen(s, 0, 1)));
	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

static char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		slen;
	char		*substr;

	slen = ft_modstrlen(s, 0, 1);
	substr = NULL;
	if (len > slen - start)
		len = slen - start;
	substr = (char *)malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*aux2_gnl(char **buff, char **prebff, char **line, int fd)
{
	int	bytesread;

	*line = ft_modstrjoin(prebff, ft_modstrdup(*buff));
	if (!(*line))
		return (ft_freevar(buff), ft_freevar(prebff));
	while (!ft_strchr(*line, '\n'))
	{
		bytesread = read(fd, *buff, BUFFER_SIZE);
		(*buff)[bytesread] = 0;
		if (bytesread <= 0 && (*line)[0])
			return (ft_freevar(buff), *line);
		if (!ft_strchr(*buff, '\n'))
			*line = ft_modstrjoin(line, ft_modstrdup(*buff));
		else
			*line = ft_modstrjoin(line, ft_substr(*buff, 0,
						ft_modstrlen(*buff, '\n', 1) + 1));
		if (!(*line))
			return (ft_freevar(buff), ft_freevar(prebff));
	}
	*prebff = ft_substr(*buff, ft_modstrlen(*buff, '\n', 1) + 1, BUFFER_SIZE);
	return (ft_freevar(buff), *line);
}

char	*aux1_gnl(char **buff, char **prebff, char **line, char **tmp)
{
	if (!ft_strchr(*prebff, '\n') && ft_strchr(*buff, '\n'))
	{
		*line = ft_modstrjoin(prebff,
				ft_substr(*buff, 0, ft_modstrlen(*buff, '\n', 1) + 1));
		if (!(*line))
			return (ft_freevar(buff), ft_freevar(prebff));
		*prebff = ft_substr(*buff,
				ft_modstrlen(*buff, '\n', 1) + 1, BUFFER_SIZE);
		if (!(*prebff))
			return (ft_freevar(buff), ft_freevar(line));
		return (ft_freevar(buff), *line);
	}
	if (ft_strchr(*prebff, '\n'))
	{
		*tmp = ft_modstrdup(*prebff);
		*line = ft_substr(*prebff, 0, ft_modstrlen(*prebff, '\n', 1) + 1);
		if (!(*line))
			return (ft_freevar(buff), ft_freevar(prebff), ft_freevar(tmp));
		ft_freevar(prebff);
		*prebff = ft_substr(*tmp, ft_modstrlen(*tmp, '\n', 1) + 1, BUFFER_SIZE);
		if (!(*prebff))
			return (ft_freevar(buff), ft_freevar(line), ft_freevar(tmp));
		return (ft_freevar(buff), ft_freevar(tmp), *line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*prebff;
	char		*buff;
	char		*line;
	int			bytesread;
	char		*tmp;

	line = NULL;
	bytesread = 1;
	buff = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buff)
		return (ft_freevar(&prebff), ft_freevar(&buff));
	if (!ft_strchr(prebff, '\n'))
		bytesread = read(fd, buff, BUFFER_SIZE);
	if (bytesread == 0 && prebff && prebff[0])
	{
		tmp = ft_modstrdup(prebff);
		return (ft_freevar(&buff), ft_freevar(&prebff), tmp);
	}
	if (bytesread <= 0)
		return (ft_freevar(&buff), ft_freevar(&prebff));
	if (ft_strchr(prebff, '\n') || ft_strchr(buff, '\n'))
		return (aux1_gnl(&buff, &prebff, &line, &tmp));
	if (!ft_strchr(prebff, '\n') && !ft_strchr(buff, '\n'))
		return (aux2_gnl(&buff, &prebff, &line, fd));
	return (NULL);
}
/* #include <fcntl.h>

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	
	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
	{
		printf("Error: 
		Wrong number of arguments\nWrite 
		../tests/[testfile] as argument\n");
		return (1);
	}
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	printf("\n$%s$\n", line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		printf("\n$%s$\n", line);
	}
	close(fd);
} */
