/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:06:32 by sara              #+#    #+#             */
/*   Updated: 2023/01/27 12:39:08 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	l[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*str;

	str = NULL;
	if (fd < 0 || FOPEN_MAX < fd)
		return (NULL);
	if (!l[fd][0])
		l[fd][read(fd, l[fd], BUFFER_SIZE)] = 0;
	while (l[fd][0])
	{
		str = ft_strjoin(str, l[fd]);
		if (!str)
			return (NULL);
		if (gnl_bzero(l[fd]))
			break ;
		if (read(fd, 0, 0) < 0)
		{
			free(str);
			return (NULL);
		}
		l[fd][read(fd, l[fd], BUFFER_SIZE)] = 0;
	}
	return (str);
}

/*int main()
{
	char *line;
	char *line2;
	char *line3;
	int fd1;
	int fd2;
	int fd3;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	line = get_next_line(fd1);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);

	printf("%s", line);
	printf("%s", line2);
	printf("%s", line3);

	free(line);
	free(line2);
	free(line3);
}*/
