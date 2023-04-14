/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:06:36 by sara              #+#    #+#             */
/*   Updated: 2023/04/14 21:15:00 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		l[BUFFER_SIZE + 1];
	char			*str;

	str = NULL;
	if (fd < 0 || FOPEN_MAX < fd)
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

/*int	main(void)
{
	int	fd;

    fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}*/