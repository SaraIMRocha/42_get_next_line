/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:06:32 by sara              #+#    #+#             */
/*   Updated: 2023/01/24 17:56:46 by sara             ###   ########.fr       */
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
