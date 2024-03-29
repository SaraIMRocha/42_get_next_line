/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:06:26 by sara              #+#    #+#             */
/*   Updated: 2023/04/18 14:50:30 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i + (str[i] == '\n'));
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	a;
	size_t	b;
	char	*str;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	a = 0;
	b = 0;
	while (s1 && s1[a])
		str[b++] = s1[a++];
	a = 0;
	while (s2 && s2[a] && s2[a] != '\n')
		str[b++] = s2[a++];
	if (s2[a] == '\n')
		str[b++] = '\n';
	str[b] = '\0';
	free(s1);
	return (str);
}

int	gnl_bzero(char *buf)
{
	int		a;
	int		b;
	int		nl;

	a = 0;
	b = 0;
	nl = 0;
	while (buf[a])
	{
		if (nl)
			buf[b++] = buf[a];
		if (buf[a] == '\n')
			nl = 1;
		buf[a++] = '\0';
	}
	return (nl);
}
