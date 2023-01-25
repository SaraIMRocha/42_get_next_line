/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:06:36 by sara              #+#    #+#             */
/*   Updated: 2023/01/24 17:52:00 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		l[BUFFER_SIZE + 1];
	char			*str;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || FOPEN_MAX < fd)
		return (NULL);
	if (!l[0])
		l[read(fd, l, BUFFER_SIZE)] = 0;
	while (l[0])
	{
		str = ft_strjoin(str, l);
		if (!str)
			return (NULL);
		if (gnl_bzero(l) == 1)
			break ;
		if (read(fd, l, 0) < 0)
		{
			free(str);
			return (NULL);
		}
		l[read(fd, l, BUFFER_SIZE)] = 0;
	}
	return (str);
}

/*char	*get_next_line(int fd)
{
	static char	l[BUFFER_SIZE + 1];
	char		*next_line;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1 || FOPEN_MAX < fd)
		return (NULL);
	if (!l[0])
		l[read(fd, l, BUFFER_SIZE)] = 0;
	next_line = ft_strjoin(0, l);
	if (gnl_bzero(l) > 0)
		return (next_line);
	i = read(fd, l, BUFFER_SIZE);
	if (i < 0)
	{
		free(next_line);
		return (NULL);
	}
	while (i > 0)
	{
		next_line = ft_strjoin(next_line, l);
		if (gnl_bzero(l) > 0)
			break ;
		i = read(fd, l, BUFFER_SIZE);
	}
	return (next_line);
}*/

/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/